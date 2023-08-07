//
// Created by haibo on 8/1/23.
//
#include <thread>
#include <future>
#include <functional>
#include <mutex>
#include <queue>
#include <sched.h>
#include <unistd.h>
#include <memory>
#include <type_traits>
#include <iostream>

using Callable = std::packaged_task<void()>;

struct MonitoredQueue {
    void push(Callable& callable);

    Callable pop();

    void stop(){
      stopped_ = true;
    };

    std::queue<Callable> work_queue_;
    std::mutex mt_queue_;                     // Mutex to guard the usage of working queue
    std::condition_variable cv_queue_;        // wait condition when queue is empty.
    bool stopped_;
};


class PinCoreExecutor {
public:
    PinCoreExecutor(uint16_t core, std::shared_ptr<MonitoredQueue>& sp_work_queue);

    void run() {
      std::cout << "start run thread on core[" << (int)pinned_core_ << "]"  << std::endl;
      while(!sp_work_queue_->stopped_) {
        auto task = sp_work_queue_->pop();
        task();
      }
    }
private:
    std::unique_ptr<std::thread> t_;
    uint16_t pinned_core_;
    std::shared_ptr<MonitoredQueue> sp_work_queue_;
};

class CPUThreadPool {
public:
  explicit CPUThreadPool();

  template<class F> auto asyncall(F &&func) {
    using ResultType = std::invoke_result_t<std::decay_t<F>>;

    std::packaged_task<ResultType()> pt(std::forward<F>(func));
    std::future<ResultType> future = pt.get_future();
    Callable task(
        [pt = std::move(pt)]() mutable { pt(); }
    );
    sp_work_queue_->push(task);
    return future;
  }

private:
  std::shared_ptr<MonitoredQueue> sp_work_queue_;
  std::vector<std::unique_ptr<PinCoreExecutor>> workers_;
};

