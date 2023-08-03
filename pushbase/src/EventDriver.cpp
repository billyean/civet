//
// Created by haibo on 8/2/23.
//

#include "EventDriver.h"

template <typename Data>
PipelineRunner::PipelineRunner(std::vector<std::unique_ptr<Task<Data>>> &tasks,
                               const std::function<void()> callback_on_succeed,
                               const std::function<void()> callback_on_exception, int pos):
    tasks_(std::move(tasks)),  callback_on_succeed_(callback_on_succeed), callback_on_exception_(callback_on_exception), pos_(pos) {
  cancelled_ = false;
}

EventDriver::EventDriver(uint64_t initSize, bool source_ready): source_ready_(source_ready), execute_exception_(false) {

}