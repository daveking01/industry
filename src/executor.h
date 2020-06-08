#pragma once

#include <atomic>
#include <thread>

#include "event.h"

namespace industry {
class Executor {
 public:
  Executor();
  ~Executor();

  void Post(std::shared_ptr<Event> event);

  void Wait();

  void Quit();

 private:
  std::thread t_;
  EventQueue eq_;
};
}  // namespace industry