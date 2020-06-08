#pragma once

enum SocketEventType {
  SOCKET_INITIALIZE,  //初始化
  SOCKET_ACCEPT,      //有新连接接入
  SOCKET_RECV,        //读事件
  SOCKET_SEND,        //写事件
  SOCKET_ERROR,       //错误事件
  SOCKET_CLOSE        //关闭事件
};

