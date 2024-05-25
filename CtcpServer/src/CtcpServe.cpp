#include "CtcpServe.h"
//初始化监听socket
bool CtcpServe::initserve(const unsigned short in_port){
    //创建监听socket
    if((m_listenfd=socket(AF_INET,SOCK_STREAM,0))==-1) return false;
    //初始化端口
    m_port=in_port;
    //绑定用于通讯的ip与端口到socket上
    //创建包含ip与端口的结构体
    struct sockaddr_in servaddr;
    memset(&servaddr,0,sizeof(servaddr));
    //设置协议族（IPV4）
    servaddr.sin_family=AF_INET;
    //存入端口
    servaddr.sin_port=htons(m_port);
    //存入ip地址
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    //为监听socket分配ip与端口
    if((bind(m_listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr)))==-1){
        this->listenclose();
    }
    //将socket设置为可连接（监听）状态
    if((listen(m_listenfd,5))==-1){
        this->listenclose();
    }
    return true;
}
//取出一个客户端ip
bool CtcpServe::accept(){
    //创建包含客户端ip与端口的结构体
    struct sockaddr_in caddr;
    //socklen_t：为保证任何环境都与int一致而设置的类型，满足accept第三个参数的需求
    socklen_t addrlen=sizeof(caddr);
    //接收客户端请求
    if((m_clientfd=::accept(m_listenfd,(struct sockaddr*)&caddr,&addrlen))==-1) return false;
    //将客户端地址由大端序转为字符串
    m_clientip=inet_ntoa(caddr.sin_addr);
    return true;
}

const string & CtcpServe::clientip() const{
    return m_clientip;
}

bool CtcpServe::send(const string &buffer){
    //判断是否连接成功
    if(m_clientfd==-1) return false;
    //发送
    if((::send(m_clientfd,buffer.data(),buffer.size(),0))<=0) return false;
    return true;
}

bool CtcpServe::recv(string &buffer,const size_t maxlen){
    //初始化buffer
    buffer.clear();
    buffer.resize(maxlen);
    int readn=::recv(m_clientfd,&buffer[0],buffer.size(),0);
    if(readn<=0){
        buffer.clear();
        return false;
    } 
    buffer.resize(readn);
    return true;
}

bool CtcpServe::listenclose(){
    //判断是否连接成功
    if(m_listenfd==-1) return false;
    ::close(m_listenfd);
    m_listenfd=-1;
    return true;
}

bool CtcpServe::clientclose(){
    //判断是否连接成功
    if(m_clientfd==-1) return false;
    ::close(m_clientfd);
    m_clientfd=-1;
    return true;
}

CtcpServe::~CtcpServe(){
    this->listenclose();
    this->clientclose();
}
