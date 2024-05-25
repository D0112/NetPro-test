#include "CtcpClient.h"

bool CtcpClient::connect(const string &clientip,const unsigned short clientport){
    //判断是否已连接
    if(m_clientfd!=-1) return false;
    //初始化服务端ip与端口
    m_clientip=clientip;
    m_clientport=clientport;

    //创建客户端socket
    if((m_clientfd=socket(AF_INET,SOCK_STREAM,0))==-1) return false;

    //创建包含ip与端口的结构体
    struct sockaddr_in serveaddr;
    //初始化结构体
    memset(&serveaddr,0,sizeof(serveaddr));
    serveaddr.sin_family=AF_INET;
    //存入服务器端口
    serveaddr.sin_port=htons(m_clientport);
    //存入服务器ip
    struct hostent* h;
    if((h=gethostbyname(m_clientip.c_str()))==nullptr){
        ::close(m_clientfd);
        m_clientfd=-1;
        return false;
    }
    memcpy(&serveaddr.sin_addr,h->h_addr,h->h_length);
    //向服务器发送连接请求
    if(::connect(m_clientfd,(struct sockaddr*)&serveaddr,sizeof(serveaddr))==-1){
        ::close(m_clientfd);
        m_clientfd=-1;
        return false;
    }
    return true;
}

bool CtcpClient::send(const string &buffer){
    //判断是否已连接
    if(m_clientfd==-1){
        return false;
    }
    //发送
    if((::send(m_clientfd,buffer.data(),buffer.size(),0))<=0){
        return false;
    }
    return true;
}

bool CtcpClient::recv(string &buffer,const size_t maxlen){
    //初始化buffer
    buffer.clear();
    buffer.resize(maxlen);
    //接收
    int readn=::recv(m_clientfd,&buffer[0],buffer.size(),0);
    //判断接收是否成功
    if(readn<=0){
        buffer.clear();
        return false;
    }
    //重置buffer大小
    buffer.resize(readn);
    return true;
}

bool CtcpClient::close(){
    //判断是否已连接
    if(m_clientfd==-1) return false;
    //关闭
    ::close(m_clientfd);
    m_clientfd=-1;
    return true;
}
CtcpClient::~CtcpClient(){
    close();
}