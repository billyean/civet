//
// Created by haibo on 8/2/23.
//
#include <cstdint>
#include <functional>
#include <memory>
#include <future>
#include "executors/CPUThreadPool.h"
#include "Operator.h"
#include "PipelineDriver.h"

static CPUThreadPool execution_pool;

template <typename Data>
struct SmallResultCache {
  std::vector<std::unique_ptr<Data>> morsels;

  std::unique_ptr<Data> combine();
};

template<typename T>
struct DoNothingHandler {
  auto isTrival(T t)  { return false; }

  void saveTrival(T t) {}

  void finalize(std::vector<T> results) {}
};

template <typename T, typename TrivalHandler = DoNothingHandler<T>>
class PipelineRunner {
public:
  PipelineRunner(std::vector<std::unique_ptr<SingleOp<T>>>& tasks, const std::function<void()> callback_on_succeed,
            const std::function<void()> callback_on_exception, int pos);

  bool run();               // Run the pipeline runner with async flavor.

  void cancel() {           // Cancel the execution of pipeline runner.
    cancelled_ = true;
  }
private:
  std::vector<std::unique_ptr<SingleOp<T>>> tasks_;
  std::function<void()> callback_on_succeed_;
  std::function<void()> callback_on_exception_;
  uint16_t pos_;
  bool cancelled_ = false;
  TrivalHandler handle_;
};



template <class R>
class PipelineJobDriver: public PipelineDriver {
  struct JobMonitor {
    uint64_t size;                             // only determined when source_ready_ is true
    std::atomic<uint64_t> ct_success;
    std::atomic<bool> execute_exception;
    std::mutex mt_end;
    std::condition_variable cv_end;


    bool wait_for_end() {
      std::unique_lock<std::mutex> qlock(mt_end);
      cv_end.wait(qlock, [this](){ return !execute_exception && size != ct_success;});
      qlock.unlock();
    }
  };


public:
  PipelineJobDriver(std::shared_ptr<StreamingQueue<R>> source, std::vector<PipelineRunner<R>> &tasks,
            std::function<R(std::vector<R>&)> sink);

  bool run();                                 // main method of driver

  void cancel();                              // cancel all worker
private:
  std::vector<R> result_;                     // Result of PipelineRunner
  std::vector<PipelineRunner<R>> tasks_;      // Execute tasks body.
  std::function<R(std::vector<R>&)> sinker_;  // one-time function called when all tasks finished successfully.
  std::function<void()> complete_;
  std::shared_ptr<std::deque<R>> source_;
  bool cancel_ = false;
};


