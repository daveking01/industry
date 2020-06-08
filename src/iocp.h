#pragma once
#include <winsock2.h>
#include <MSWSock.h>

#include "config.h"
#include "enum.h"

namespace industry {
class IOCPModel {
 public:
  IOCPModel();
  ~IOCPModel();
  bool Init(); //初始化
 private:
  bool LoadSocketLib();                     //加载套接字库
  void UnloadSocketLib() { WSACleanup(); }  //卸载套接字库
  bool InitIOCP();                          //初始化完成端口
  bool InitSocket();                        //初始化socket
  HANDLE m_hIOCP;  //完成端口句柄
  LPFN_ACCEPTEX m_lpfnAcceptEx;  // AcceptEx 和 GetAcceptExSockaddrs
                                 // 的函数指针，用于调用这两个扩展函数
  LPFN_GETACCEPTEXSOCKADDRS m_lpfnGetAcceptExSockAddrs;
};
}  // namespace industry
