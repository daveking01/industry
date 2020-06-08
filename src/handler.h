#pragma once
#include <memory>

namespace industry {
class Socket;
class Buffer;
class Handler {
 public:
  virtual ~Handler() {}

  virtual void read(std::shared_ptr<Socket>, std::shared_ptr<Buffer>) = 0;
  virtual void write(std::shared_ptr<Socket>, std::shared_ptr<Buffer>) = 0;
  virtual void error(std::shared_ptr<Socket>) = 0;
  virtual void close(std::shared_ptr<Socket>) = 0;
 private:
};
}  // namespace industry