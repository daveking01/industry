#pragma once

enum SocketEventType {
  SOCKET_INITIALIZE,  //��ʼ��
  SOCKET_ACCEPT,      //�������ӽ���
  SOCKET_RECV,        //���¼�
  SOCKET_SEND,        //д�¼�
  SOCKET_ERROR,       //�����¼�
  SOCKET_CLOSE        //�ر��¼�
};

