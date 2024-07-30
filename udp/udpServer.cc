#include "udpServer.hpp"
// #include "onlineUser.hpp"
#include <memory>
#include <fstream>
#include <unordered_map>
#include <signal.h>

using namespace std;
using namespace Server;

static void Usage(string proc)
{
    cout << "\nUsage:\n\t" << proc << "local_port\n\n";
}
void handlerMessage(string clientip, uint16_t clientport, string message)
{
    // 就可以对message进行特定的业务处理，而不关心message怎么来的 ---- server通信和业务逻辑解耦！
    cout << clientip << "[" << clientport << "]#" << message << endl;
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

    std::unique_ptr<udpServer> usvr(new udpServer(port));
    // std::unique_ptr<udpServer> usvr(new udpServer(handlerMessage, port));

    usvr->initServer();
    usvr->start();

    return 0;
}