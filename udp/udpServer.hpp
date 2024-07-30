#pragma once

#include <iostream>
#include <string>
#include <strings.h>
#include <cerrno>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

namespace Server
{

    using namespace std;

    static const string defaultIp = "0.0.0.0";
    static const int gnum = 1024;

    enum
    {
        USAGE_ERR = 1,
        SOCKET_ERR,
        BIND_ERR,
        OPEN_ERR
    };

    // typedef function<void(int, string, uint16_t, string)> func_t;

    class udpServer
    {

    public:
        udpServer(/*const func_t &cb,*/ const uint16_t &port, const string &ip = defaultIp)
            : /*_callback(cb),*/ _port(port), _ip(ip), _sockfd(-1) {}

        void initServer()
        {
            _sockfd = socket(AF_INET, SOCK_DGRAM, 0); //    创建socket
            if (_sockfd == -1)
            {
                cerr << "socket error:" << errno << ":" << strerror(errno) << endl;
                exit(SOCKET_ERR);
            }
            cout << "socket success:" << ":" << _sockfd << endl;

            // 绑定port,ip
            struct sockaddr_in local;
            bzero(&local, sizeof(local)); // 初始化
            local.sin_family = AF_INET;
            local.sin_port = htons(_port);
            // local.sin_addr.s_addr=inet_addr(_ip.c_str());
            local.sin_addr.s_addr = htonl(INADDR_ANY); // 任意地址bind

            int n = bind(_sockfd, (struct sockaddr *)&local, sizeof(local));
            if (n == -1)
            {
                cerr << "bind error:" << errno << ":" << strerror(errno) << endl;
                exit(BIND_ERR);
            }
        }

        // 启动服务器
        void start()
        {
            char buffer[gnum];
            // 死循环
            for (;;)
            {
                // 读取数据
                struct sockaddr_in peer;
                socklen_t len = sizeof(peer);
                ssize_t s = recvfrom(_sockfd, buffer, sizeof(buffer) - 1, 0, (struct sockaddr*)&peer, &len);
                if (s > 0)
                {
                    buffer[s] = 0;
                    string clientip = inet_ntoa(peer.sin_addr); // 网络序列-》int-》点分十进制
                    uint16_t clientport = ntohs(peer.sin_port);
                    string message = buffer;
                    cout << clientip << "[" << clientport << "]#" << message << endl;

                    // 对数据做处理
                    // _callback(_sockfd, clientip, clientport, message);
                }
            }
        }

        ~udpServer() {}

    private:
        uint16_t _port;
        string _ip;
        int _sockfd;      // 套接字文件描述符
        // func_t _callback; // 回调函数
    };

}