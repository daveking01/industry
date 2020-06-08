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
  bool Init(); //��ʼ��
 private:
  bool LoadSocketLib();                     //�����׽��ֿ�
  void UnloadSocketLib() { WSACleanup(); }  //ж���׽��ֿ�
  bool InitIOCP();                          //��ʼ����ɶ˿�
  bool InitSocket();                        //��ʼ��socket
  HANDLE m_hIOCP;  //��ɶ˿ھ��
  LPFN_ACCEPTEX m_lpfnAcceptEx;  // AcceptEx �� GetAcceptExSockaddrs
                                 // �ĺ���ָ�룬���ڵ�����������չ����
  LPFN_GETACCEPTEXSOCKADDRS m_lpfnGetAcceptExSockAddrs;
};
}  // namespace industry
