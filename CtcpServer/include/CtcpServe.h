#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
using namespace std;
// 包含sockaddr_in结构体与客户端socket

struct SockInfo
{
    struct sockaddr_in addr;
    int fd;
};

class CtcpServe
{
private:
    string m_clientip;
    unsigned short m_port;
    int m_infoMax;
    SockInfo m_infos[512];

public:
    int m_listenfd;
    int m_clientfd;
    CtcpServe();
    bool initserve(const unsigned short in_port);
    pair<bool, SockInfo *> accept();
    bool send(SockInfo *pinfo, string &buffer);
    const string &clientip() const;
    bool recv(SockInfo *pinfo, string &buffer, size_t maxlen);
    bool listenclose();
    bool clientclose();
    ~CtcpServe();
};
