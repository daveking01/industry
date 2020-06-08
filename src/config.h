#pragma once

class SocketConfig {
 public:
  int buffer_size() { return buffer_size_init; }

 private:
  int buffer_size_init_{1024}; //初始化收发缓冲区大小
  int back_log{1024}; //listen socket 队列长队
};