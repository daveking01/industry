#include "iocp.h"

namespace industry {
IOCPModel::IOCPModel() {}
IOCPModel::~IOCPModel() {}

bool IOCPModel::InitIOCP() {
  m_hIOCP = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);
  if (NULL == m_hIOCP) {
    printf("������ɶ˿�ʧ�ܣ�������룺%d\n", WSAGetLastError());
    return false;
  }
  return true;
}

bool IOCPModel::Init() {

}
}