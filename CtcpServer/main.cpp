#include "CtcpServe.h"
#include <signal.h>
#include "_freecplus.h"
#include <pthread.h>
#include "ThreadPool.h"
#include "ThreadPool.cpp"

using namespace std;
void ThredFunc(void *arg);
void *acceptconn(void *arg);
void Mainexit(int sig);
CLogFile Logfile;
CtcpServe ctcpserve;

int main(int argc, char *argv[])

{
    if (Logfile.Open("./Logfile/log") == false)
    {
        cout << "Logfile.Open is Wrong" << endl;
    }
    Logfile.Write("LOG Successfully \n");
    // 避免出现僵尸进程，并关闭全部信号
    for (int ii = 0; ii < 100; ++ii)
        signal(ii, SIG_IGN);
    // if (fork() > 0)
    //     exit(0);
    signal(SIGINT, Mainexit);
    signal(SIGTERM, Mainexit);
    if (argc != 2)
    {
        Logfile.Write("服务端端口号5005 \n");
        return -1;
    }

    if (ctcpserve.initserve(atoi(argv[1])) == false)
    {
        Logfile.Write("initserve() \n");
        return -1;
    }
    ThreadPool<SockInfo *> *pool = new ThreadPool<SockInfo *>(3, 10);
    pthread_t tid;
    pthread_create(&tid, NULL, acceptconn, (void *)pool);
    pthread_detach(tid);
    pthread_exit(0);
    return 0;
}
void *acceptconn(void *arg)
{
    ThreadPool<SockInfo *> *pool = static_cast<ThreadPool<SockInfo *> *>(arg);
    while (true)
    {
        SockInfo *pinfo;
        pinfo = new SockInfo;
        pair<bool, SockInfo *> tmp = (ctcpserve.accept(pinfo));
        if (tmp.first == false)
        {
            Logfile.Write("accept() \n");
            delete pinfo;
            break;
        }
        // // 关闭多余的socket
        // if (fork() > 0)
        // {
        //     ctcpserve.clientclose();
        //     continue;
        // }
        // ctcpserve.listenclose();
        pinfo = tmp.second;
        Logfile.Write("客户端已连接 \n");
        // Logfile.Write("pinfo->fd:%d\n", pinfo->fd);
        // Logfile.Write("m_clientfd:%d\n", ctcpserve.m_clientfd);
        Task<SockInfo *> task(ThredFunc, pinfo);
        pool->addTask(task);
    }
    Logfile.Write("pool delete\n");
    delete pool;
    pthread_exit(0);
}

void ThredFunc(void *arg)
{
    SockInfo *pinfo = (struct SockInfo *)arg;
    string buffer;
    while (true)
    {
        if (ctcpserve.recv(pinfo, buffer, 1024) == false)
        {
            Logfile.Write("recv() \n");
            break;
        }
        Logfile.Write("接收：%s\n", buffer.c_str());
        buffer = "ok";
        if (ctcpserve.send(pinfo, buffer) == false)
        {
            Logfile.Write("send() \n");
            break;
        }
        Logfile.Write("发送：%s\n", buffer.c_str());
    }
    Logfile.Write("客户端退出，子线程关闭\n");
    // pthread_exit(0);
}

void Mainexit(int sig)
{
    ctcpserve.listenclose();
    Logfile.Write("服务端关闭，主进程退出\n");
    exit(0);
}