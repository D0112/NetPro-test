#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<unistd.h>
#include<netdb.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
using namespace std;

class CtcpServe
{
private:
    int m_listenfd;
    int m_clientfd;
    string m_clientip;
    unsigned short m_port;
public:
    CtcpServe():m_listenfd(-1),m_clientfd(-1){}
    bool initserve(const unsigned short in_port);
    bool accept();
    bool send(const string &buffer);
    const string& clientip()const;
    bool recv(string &buffer,const size_t maxlen);
    bool listenclose();
    bool clientclose();
    ~CtcpServe();
};

