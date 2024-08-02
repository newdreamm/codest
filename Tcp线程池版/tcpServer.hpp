#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <pthread.h>

#include "log.hpp"
#include "Task.hpp"
#include "ThreadPool.hpp"

namespace server
{
    enum
    {
        USAGE_ERR = 1,
        SOCKET_ERR,
        BIND_ERR,
        LISTEN_ERR
    };

    static const uint16_t gport = 8080;
    static const int gbacklog = 5;

    class TcpServer;

    class ThreadData
    {
    public:
        ThreadData(TcpServer *self, int sock) : _self(self), _sock(sock) {}
        // ~ThreadData() {}

    private:
        TcpServer *_self;
        int _sock;
    };

    class TcpServer
    {
    private:
        int _listensock; // 不是用来进行数据通信的，它是用来监听链接到来，获取新链接的！
        uint16_t _port;

    public:
        TcpServer(const uint16_t &port = gport) : _listensock(-1), _port(port) {}

        void initServer()
        {
            // 创建套接字对象
            _listensock = socket(AF_INET, SOCK_STREAM, 0);
            if (_listensock < 0)
            {
                logMessage(FATAL, "create socket error");
                exit(SOCKET_ERR);
            }
            logMessage(NORMAL, "create socket succes:%d", _listensock);

            // bind绑定自己的网络信息
            struct sockaddr_in local;
            memset(&local, 0, sizeof(local));
            local.sin_family = AF_INET;
            local.sin_port = htons(_port);
            local.sin_addr.s_addr = INADDR_ANY;
            if (bind(_listensock, (struct sockaddr *)&local, sizeof(local)) < 0)
            {
                logMessage(FATAL, "bind socket error");
                exit(BIND_ERR);
            }
            logMessage(NORMAL, "bind socket succes");

            // 设置监听状态
            if (listen(_listensock, gbacklog) < 0)
            {
                logMessage(FATAL, "listen socket error");
                exit(LISTEN_ERR);
            }
            logMessage(NORMAL, "listen socket success");
        }

        void start()
        {
            // 线程池初始化
            ThreadPool<Task>::getInstance()->run();
            logMessage(NORMAL, "Thread init succes");
            for (;;)
            {
                // 获取新连接
                // sock,和client通信的fd
                struct sockaddr_in peer;
                socklen_t len = sizeof(peer);
                int sock = accept(_listensock, (struct sockaddr *)&peer, &len);
                if (sock < 0)
                {
                    logMessage(ERROR, "accept error,next");
                    continue;
                }
                logMessage(NORMAL, "accept a new link success, get new sock: %d", sock);

                ThreadPool<Task>::getInstance()->push(Task(sock, serviceIO));
            }
        }

        ~TcpServer() {}
    };

} // namespace server