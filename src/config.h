#pragma once

class SocketConfig {
 public:
  int buffer_size() { return buffer_size_init; }

 private:
  int buffer_size_init_{1024}; //��ʼ���շ���������С
  int back_log{1024}; //listen socket ���г���
};