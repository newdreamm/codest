#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include "log.hpp"
#include "protocol.hpp"

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

    // const Request &req: 输入型
    // Response &resp: 输出型
    typedef std::function<bool(const Request &req, Response &resp)> func_t;

    // 保证解耦
    void handlerEntery(int sock, func_t func)
    {
        std::string inbuffer;
        while (true)
        {
            // 1. 读取："content_len"\r\n"x op y"\r\n
            std::string req_text, req_str;
            // 保证收到的是一个完整的请求
            if (!recvPackage(sock, inbuffer, &req_text))
                return;
            std::cout << "带报头的请求：\n"<< req_text << std::endl;
            // 去掉包头
            if (!deLength(req_text, &req_str))
                return;
            std::cout << "去掉报头的正文：\n"<< req_str << std::endl;

            // 2.对请求Request反序列化
            Request req;
            if (!req.deserialize(req_str))
                return;

            // 3.计算处理--业务逻辑
            Response resp;
            func(req, resp); // req的处理结果，全部放入到了resp,然后再回来。

            // 4.对响应Response,进行序列化
            std::string resp_str;
            resp.serialize(&resp_str);
            std::cout << "计算完成, 序列化响应: " << resp_str << std::endl;

            // 发送响应
            std::string send_string = enLength(resp_str);
            std::cout << "构建完成完整的响应\n"<< send_string << std::endl;
            send(sock, send_string.c_str(), send_string.size(), 0);
        }
    }


    class CalServer
    {
    public:
        CalServer(const uint16_t &port = gport) : _listensock(-1), _port(port)
        {
        }
        void initServer()
        {
            // 1. 创建socket文件套接字对象
            _listensock = socket(AF_INET, SOCK_STREAM, 0);
            if (_listensock < 0)
            {
                logMessage(FATAL, "create socket error");
                exit(SOCKET_ERR);
            }
            logMessage(NORMAL, "create socket success: %d", _listensock);

            // 2. bind绑定自己的网络信息
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
            logMessage(NORMAL, "bind socket success");

            // 3. 设置socket 为监听状态
            if (listen(_listensock, gbacklog) < 0) // 第二个参数backlog后面在填这个坑
            {
                logMessage(FATAL, "listen socket error");
                exit(LISTEN_ERR);
            }
            logMessage(NORMAL, "listen socket success");
        }
        void start(func_t func)
        {
            for (;;)
            {
                // 4. server 获取新链接
                // sock, 和client进行通信的fd
                struct sockaddr_in peer;
                socklen_t len = sizeof(peer);
                int sock = accept(_listensock, (struct sockaddr *)&peer, &len);
                if (sock < 0)
                {
                    logMessage(ERROR, "accept error, next");
                    continue;
                }
                logMessage(NORMAL, "accept a new link success, get new sock: %d", sock); //

                // 多进程版
                pid_t id = fork();
                if (id == 0) // child
                {
                    close(_listensock);
                    // if(fork()>0) exit(0);
                    //  serviceIO(sock);
                    handlerEntery(sock, func);
                    close(sock);
                    exit(0);
                }
                close(sock);

                // father
                pid_t ret = waitpid(id, nullptr, 0);
                if (ret > 0)
                {
                    logMessage(NORMAL, "wait child success"); // ?
                }
            }
        }
        ~CalServer() {}

    private:
        int _listensock; // 不是用来进行数据通信的，它是用来监听链接到来，获取新链接的！
        uint16_t _port;
    };

} // namespace server