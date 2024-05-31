#include "CtcpServe.h"

CtcpServe::CtcpServe()
{
    m_clientfd = -1;
    m_listenfd = -1;
}

// 初始化监听socket
bool CtcpServe::initserve(const unsigned short in_port)
{
    // 创建监听socket
    if ((m_listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        return false;
    // 初始化端口
    m_port = in_port;
    // 绑定用于通讯的ip与端口到socket上
    // 创建包含ip与端口的结构体
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    // 设置协议族（IPV4）
    servaddr.sin_family = AF_INET;
    // 存入端口
    servaddr.sin_port = htons(m_port);
    // 存入ip地址
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    // 为监听socket分配ip与端口
    if ((bind(m_listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr))) == -1)
    {
        return this->listenclose();
    }
    // 将socket设置为可连接（监听）状态
    if ((listen(m_listenfd, 5)) == -1)
    {
        return this->listenclose();
    }
    cout << m_listenfd << endl;
    return true;
}
// 取出一个客户端ip
pair<bool, SockInfo *> CtcpServe::accept(SockInfo *pinfo)
{
    socklen_t addrlen = sizeof(struct sockaddr_in);
    // 接收客户端请求
    if ((m_clientfd = ::accept(m_listenfd, (struct sockaddr *)&pinfo->addr, &addrlen)) == -1)
    {
        this->listenclose();
        return make_pair(false, pinfo);
    }
    pinfo->fd = m_clientfd;
    // 将客户端地址由大端序转为字符串
    m_clientip = inet_ntoa(pinfo->addr.sin_addr);
    return make_pair(true, pinfo);
}

const string &CtcpServe::clientip() const
{
    return m_clientip;
}

bool CtcpServe::send(SockInfo *pinfo, string &buffer)
{
    // 判断是否连接成功
    if (pinfo->fd == -1)
        return false;

    // 发送
    if ((::send(pinfo->fd, buffer.data(), buffer.size(), 0)) <= 0)
        return false;
    return true;
}

bool CtcpServe::recv(SockInfo *pinfo, string &buffer, size_t maxlen)
{
    // 初始化buffer
    buffer.clear();
    buffer.resize(maxlen);
    int readn = ::recv(pinfo->fd, &buffer[0], buffer.size(), 0);
    if (readn <= 0)
    {
        buffer.clear();
        return false;
    }
    buffer.resize(readn);
    return true;
}

bool CtcpServe::listenclose()
{
    // 判断是否连接成功
    if (m_listenfd == -1)
        return false;
    ::close(m_listenfd);
    m_listenfd = -1;
    return false;
}

bool CtcpServe::clientclose()
{
    // 判断是否连接成功
    if (m_clientfd == -1)
        return false;
    ::close(m_clientfd);
    m_clientfd = -1;
    return false;
}

CtcpServe::~CtcpServe()
{
    this->listenclose();
    this->clientclose();
}
