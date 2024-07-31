#pragma once

#include <iostream>
#include <string>
#include <strings.h>
#include <cerrno>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

namespace Client
{
    using namespace std;

    class udpClient
    {
    public:
        udpClient(const string &serverip, const uint16_t &serverport)
            : _serverip(serverip), _serverport(serverport), _sockfd(-1), _quit(false)
        {
        }
        void initClient()
        {
            // 创建socket
            _sockfd = socket(AF_INET, SOCK_DGRAM, 0);
            if (_sockfd == -1)
            {
                cerr << "socket error: " << errno << " : " << strerror(errno) << endl;
                exit(2);
            }
            cout << "socket success: " << " : " << _sockfd << endl;

            // 2. client要不要bind[必须要的]，client要不要显示的bind，需不需程序员自己bind？不需要！！！
            // 写服务器的是一家公司，写client是无数家公司 -- 由OS自动形成端口进行bind！-- OS在什么时候，如何bind
        }
        void run()
        {
            struct sockaddr_in server;
            memset(&server, 0, sizeof(server)); // 初始化
            server.sin_family = AF_INET;
            server.sin_addr.s_addr = inet_addr(_serverip.c_str());
            server.sin_port = htons(_serverport);

            string message;
            char buffer_cmd[1024];
            while (!_quit)
            {
                cout << "我的远程机器# ";
                // cin >> message;

                fgets(buffer_cmd, sizeof(buffer_cmd), stdin);
                message = buffer_cmd;

                sendto(_sockfd, message.c_str(), message.size(), 0, (struct sockaddr *)&server, sizeof(server));

                char buffer[1024];
                struct sockaddr_in temp;
                socklen_t temp_len = sizeof(temp);
                size_t n = recvfrom(_sockfd, buffer, sizeof(buffer) - 1, 0, (struct sockaddr *)&temp, &temp_len);
                if (n >= 0)
                    buffer[n] = 0;
                cout << "\n" << buffer << endl;
            }
        }
        ~udpClient()
        {
        }

    private:
        int _sockfd;
        string _serverip;
        uint16_t _serverport;
        bool _quit;
    };
} // namespace Client
