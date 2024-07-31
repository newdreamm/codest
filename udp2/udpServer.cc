#include "udpServer.hpp"
// #include "onlineUser.hpp"
#include <memory>
#include <fstream>
#include <unordered_map>
#include <signal.h>

using namespace std;
using namespace Server;

const std::string dictTxt = "./dict.txt";
unordered_map<string, string> dict;

static void Usage(string proc)
{
    cout << "\nUsage:\n\t" << proc << "local_port\n\n";
}

static bool cutString(const string &target, string *s1, string *s2, const string &sep)
{
    auto pos = target.find(sep);
    if (pos == string::npos)
        return false;
    *s1 = target.substr(0, pos);
    *s2 = target.substr(pos + sep.size());
    return true;
}

static void initDict()
{
    ifstream in(dictTxt, std::ios::binary);
    if (!in.is_open())
    {
        cerr << "open file" << dictTxt << "error" << endl;
        exit(OPEN_ERR);
    }
    string line;
std:
    string key, value;
    while (getline(in, line))
    {
        if (cutString(line, &key, &value, ":"))
        {
            dict.insert(make_pair(key, value));
        }
    }
    in.close();
    cout << "load dict success" << endl;
}

void reload(int signo)
{
    (void)signo;
    initDict();
}

static void debugPrint()
{
    for (auto &dt : dict)
    {
        cout << dt.first << "#" << dt.second << endl;
    }
}

void handlerMessage(int sockfd, string clientip, uint16_t clientport, string message)
{
    // 对message进行特定的业务处理，而不关心message怎么来的 ---- server通信和业务逻辑解耦！
    string response_message;
    auto iter = dict.find(message);
    if (iter == dict.end())
        response_message = "unknown";
    else
        response_message = iter->second;

    // 返回
    struct sockaddr_in client;
    bzero(&client, sizeof(client));

    client.sin_family = AF_INET;
    client.sin_port = htons(clientport);
    client.sin_addr.s_addr = inet_addr(clientip.c_str());

    sendto(sockfd, response_message.c_str(), response_message.size(), 0, (struct sockaddr *)&client, sizeof(client));
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        Usage(argv[0]);
        exit(USAGE_ERR);
    }
    uint16_t port = atoi(argv[1]);
    // string ip =argv[1];
    signal(2, reload);
    initDict();
    debugPrint();

    // std::unique_ptr<udpServer> usvr(new udpServer(port));
    std::unique_ptr<udpServer> usvr(new udpServer(handlerMessage, port));

    usvr->initServer();
    usvr->start();

    return 0;
}