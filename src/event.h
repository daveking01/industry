#pragma once

#include <queue>
#include <memory>
#include <atomic>

namespace industry {
class Event {
 public:
  virtual ~Event() {}
  virtual int DoEvent() = 0;
};

class SpinLock {
 public:
  SpinLock() {}
  ~SpinLock() { lock_.clear(); }
  void Lock() {
    while (lock_.test_and_set())
      ;
  }

  void UnLock() { lock_.clear(); }

 private:
  std::atomic_flag lock_{false};
};

class EventQueue {
 public:

  void Push(std::shared_ptr<Event> event) {
    lock_.Lock();
    queue_.push(event);
    lock_.UnLock();
  }

  std::shared_ptr<Event> Pop() {
    lock_.Lock();
    auto e = queue_.front();
    queue_.pop();
    lock_.UnLock();
    return e;
  }
  int size() { return queue_.size(); }
 private:
  std::queue<std::shared_ptr<Event>> queue_;
  SpinLock lock_;
};
}  // namespace industry