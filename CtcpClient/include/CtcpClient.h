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


class CtcpClient
{
private:
    int m_clientfd;
    string m_clientip;
    unsigned short m_clientport;
public:
    CtcpClient():m_clientfd(-1){}
    bool connect(const string &clientip,const unsigned short clientport);
    bool send(const string &buffer);
    bool recv(string &buffer,const size_t maxlen);
    bool close();
    ~CtcpClient();
};

