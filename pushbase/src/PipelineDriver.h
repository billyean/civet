//
// Created by haibo on 8/5/23.
//
#include <atomic>
#include <queue>
#include <mutex>
#include <condition_variable>

template <typename T>
struct StreamingQueue {       // Queue is only one consumer.
  explicit StreamingQueue(bool ready = true){
    exhausted = ready;
  }

  void inQueue(T&& t) {
    std::lock_guard lock(mutex_);
    queue.push_back(t);
    unlock_cond.notify_one();
  };

  void lastInQueue(T&& t) {
    inQueue(t);
    exhausted = true;
  }

  T* pop() {
    if (exhausted && queue.empty()) {
      return nullptr;
    }
    T t;
    if (exhausted) {
      t = std::move(queue.pop_front());
    } else {
      std::unique_lock<std::mutex> qlock(mutex_);
      while(queue.empty()) {
        unlock_cond.wait(qlock);
      }
      t = std::move(queue.pop_front());
      qlock.unlock();
    }
    std::unique_ptr<T> p = std::make_unique(t);
    return p;
  }

  std::deque<T> queue;
  std::mutex mutex_;                          // Mutex to guard the usage of working queue
  std::condition_variable unlock_cond;        // wait condition when queue is empty.
  std::atomic<bool> exhausted;
};

enum PipelineState{
  INIT,
  RUNNING,
  SUCCEED,
  FAILED,
};

class PipelineDriver {
public:
  virtual bool run() = 0;                     // main method of driver

  virtual void cancel() = 0;                  // cancel all worker
protected:
  PipelineState state_;
};
