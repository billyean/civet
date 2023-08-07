//
// Created by haibo on 8/5/23.
//

#ifndef CIVET_IOTHREADPOOL_H
#define CIVET_IOTHREADPOOL_H


class IOExecutor {
public:
  IOExecutor();

  void run() {
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

class IOThreadPool {

};


#endif //CIVET_IOTHREADPOOL_H
