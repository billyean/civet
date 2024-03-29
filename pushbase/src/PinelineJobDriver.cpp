//
// Created by haibo on 8/2/23.
//

#include "PipelineJobDriver.h"

template <typename Data>
PipelineRunner<Data>::PipelineRunner(std::vector<std::unique_ptr<SingleOp<Data>>> &tasks,
                               const std::function<void()> callback_on_succeed,
                               const std::function<void()> callback_on_exception, int pos):
    callback_on_succeed_(callback_on_succeed), callback_on_exception_(callback_on_exception),
    tasks_(std::move(tasks)),  pos_(pos) {
}

template <typename Data>
bool PipelineRunner<Data>::run() {
    try{
        state_ = RUNNING;
        for (auto iter = tasks_.cbegin(); iter != tasks_.cend() && !cancelled_; iter++) {
            *iter();
        }
        callback_on_succeed_();
        state_  = SUCCESS;
        return true;
    } catch(...) {
        callback_on_exception_();
        state_  = FAILED;
        return false;
    }
}

template <typename R>
JobDriver<R>::JobDriver(std::shared_ptr<StreamingQueue<R>> source, std::vector<PipelineRunner<R>> &tasks,
                     std::function<R(std::vector<R>&)> sink):
        source_(source), tasks_(std::move(tasks)), execute_exception_(false) {

}

template <typename R>
bool JobDriver<R>::run() {
  while ()
}

template <typename R>
void JobDriver<R>::cancel() {

}