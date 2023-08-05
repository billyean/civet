//
// Created by haibo on 8/2/23.
//
#include <cstdint>
#include <atomic>
#include <vector>
#include <functional>
#include <memory>
#include <future>
#include "MyThreadPool.h"
#include "Task.h"

static MyThreadPool execution_pool;

class RowVectorPtr;

template <typename Chunk>
struct Buffer {
  std::queue<Chunk> work_queue_;
  std::mutex ready_mutex_;                     // Mutex to guard the usage of working queue
  std::condition_variable ready_cond_;     // wait condition when queue is empty.
};

enum PipelineRunnerState{
  INIT,
  SCHEDULED,
  RUNNING,
  SUCCESS,
  FAILED
};

template <typename Data>
struct SmallResultCache {
  std::vector<std::unique_ptr<Data>> morsels;

  std::unique_ptr<Data> combine();
};

template <typename T>
class PipelineRunner {
public:
  PipelineRunner(std::vector<std::unique_ptr<Task<T>>>& tasks, const std::function<void()> callback_on_succeed,
            const std::function<void()> callback_on_exception, int pos);

  bool run();               // Run the pipeline runner with async flavor.

  void cancel() {           // Cancel the execution of pipeline runner.
    cancelled_ = true;
  }
private:
  PipelineRunnerState state_;
  std::vector<std::unique_ptr<Task<T>>> tasks_;
  std::function<void()> callback_on_succeed_;
  std::function<void()> callback_on_exception_;
  uint16_t pos_;
  bool cancelled_ = false;
};

template <class R>
class JobDriver {
public:
  JobDriver(std::shared_ptr<std::queue<R>> source, std::vector<PipelineRunner<R>> &tasks,
            std::function<R(std::vector<R>&)> sink, bool source_ready = true);

  bool run();                                 // main method of driver

  void cancel();                              // cancel all worker
private:
  bool source_ready_;                         // true only when source is exhausted
  uint64_t size_;                             // only determined when source_ready_ is true
  std::atomic<uint64_t> success_;
  std::atomic<bool> execute_exception_;
  std::vector<RowVectorPtr> result_;          // Result of PipelineRunner
  std::vector<PipelineRunner<R>> tasks_;      // Execute tasks body.

  std::function<R(std::vector<R>&)> combine_;  // one-time function called when all tasks finished successfully.

  std::function<void()> complete_;

  std::vector<std::unique_ptr<SmallResultCache<R>>> caches_;
  std::shared_ptr<std::queue<R>> source_;
  bool cancel_ = false;
};


