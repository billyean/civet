//
// Created by Haibo Yan on 8/1/23.
//

#include "CPUThreadPool.h"

#if __APPLE__
#include <mach/mach.h>
#include <mach/thread_policy.h>
#endif

void MonitoredQueue::push(Callable &callable) {
  if (!stopped_) {
    {
      std::lock_guard<std::mutex> lk(mt_queue_);
      work_queue_.push(std::move(callable));
      // release lock once push is done.
    }
    // Notify only one thread to avoid contention
    cv_queue_.notify_one();
  }
}

Callable MonitoredQueue::pop() {
  while (!stopped_) {
    std::unique_lock<std::mutex> qlock(mt_queue_);
    cv_queue_.wait(qlock, [this](){ return !work_queue_.empty();});
    Callable task = std::move(work_queue_.front());
    work_queue_.pop();
    qlock.unlock();
    return task;
  }

  // Only reach here when stop the whole process.
  Callable doNothing([]{});
  return doNothing;
}


PinCoreExecutor::PinCoreExecutor(uint16_t core, std::shared_ptr<MonitoredQueue> &sp_work_queue) :
    pinned_core_(core), sp_work_queue_(sp_work_queue)
{
  // Pin current thread to given core.
  t_ = std::make_unique<std::thread>(&PinCoreExecutor::run, this);
#ifdef THREAD_AFFINITY_POLICY
  thread_affinity_policy_data_t policy = { pinned_core_ + 1 };
  int rc = thread_policy_set(pthread_mach_thread_np(t_->native_handle()), THREAD_AFFINITY_POLICY, (thread_policy_t)&policy, 1);
    if (rc != 0) {
    throw std::runtime_error("Unable set affinity for thread");
  }
#else
  cpu_set_t cpuset;
  CPU_ZERO(&cpuset);
  CPU_SET(pinned_core_, &cpuset);
  //int rc = pthread_setaffinity_np(native_handle(), sizeof(cpu_set_t), &cpuset);
  int rc = pthread_setaffinity_np(t_->native_handle(), sizeof(cpu_set_t), &cpuset);
  if (rc != 0) {
    throw std::runtime_error("Unable set affinity for thread");
  }
#endif
}

CPUThreadPool::CPUThreadPool()  {
  sp_work_queue_ = std::make_shared<MonitoredQueue>();
  long cores = sysconf(_SC_NPROCESSORS_ONLN);
  for (long i = 0; i < cores; ++i) {
    auto sp_queue = sp_work_queue_;  // Copy queue pointer
    std::unique_ptr<PinCoreExecutor> worker(new PinCoreExecutor(i, sp_queue));
    workers_.emplace_back(std::move(worker));
  }
}
