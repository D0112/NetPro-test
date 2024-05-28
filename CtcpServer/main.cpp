#include "CtcpServe.h"
#include <signal.h>
#include "_freecplus.h"
#include <pthread.h>
using namespace std;
void *ThredFunc(void *arg);
void Pthexit(void *arg);
void Mainexit(int sig);
vector<long> vthid;
CLogFile logfile;
CtcpServe ctcpserve;

int main(int argc, char *argv[])

{
    if (logfile.Open("./logfile") == false)
    {
        cout << "logfile.Open is Wrong" << endl;
    }
    logfile.Write("LOG Successfully \n");
    // 避免出现僵尸进程，并关闭全部信号
    for (int ii = 0; ii < 100; ++ii)
        signal(ii, SIG_IGN);
    // if (fork() > 0)
    //     exit(0);
    signal(SIGINT, Mainexit);
    signal(SIGTERM, Mainexit);
    if (argc != 2)
    {
        logfile.Write("服务端端口号5005 \n");
        return -1;
    }

    if (ctcpserve.initserve(atoi(argv[1])) == false)
    {
        logfile.Write("initserve() \n");
        return -1;
    }

    while (true)
    {
        SockInfo *pinfo;
        pair<bool, SockInfo *> tmp = (ctcpserve.accept());
        if (tmp.first == false)
        {
            logfile.Write("accept() \n");
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
        logfile.Write("客户端已连接 \n");
        // logfile.Write("pinfo->fd:%d\n", pinfo->fd);
        // logfile.Write("m_clientfd:%d\n", ctcpserve.m_clientfd);

        pthread_t thid;
        if (pthread_create(&thid, NULL, ThredFunc, pinfo) != 0)
        {
            logfile.Write("Thread Create Error");
        }
        pthread_detach(thid);
        vthid.push_back(thid);
    }
    return 0;
}

void *ThredFunc(void *arg)
{
    SockInfo *pinfo = (struct SockInfo *)arg;
    pthread_cleanup_push(Pthexit, pinfo);
    pthread_setcanceltype(PTHREAD_CANCEL_DISABLE, NULL);
    string buffer;
    while (true)
    {
        if (ctcpserve.recv(pinfo, buffer, 1024) == false)
        {
            logfile.Write("recv() \n");
            break;
        }
        logfile.Write("接收：%s\n", buffer.c_str());
        buffer = "ok";
        if (ctcpserve.send(pinfo, buffer) == false)
        {
            logfile.Write("send() \n");
            break;
        }
        logfile.Write("发送：%s\n", buffer.c_str());
    }
    logfile.Write("客户端退出，子线程关闭\n");
    pthread_cleanup_pop(1);
    pthread_exit(0);
}

void Pthexit(void *arg)
{
    SockInfo *pinfo = (struct SockInfo *)arg;
    close(pinfo->fd);
    pinfo->fd = -1;
    for (int i = 0; i < vthid.size(); ++i)
    {
        if (vthid[i] == pthread_self())
        {
            vthid.erase(vthid.begin() + i);
        }
    }
}

void Mainexit(int sig)
{
    ctcpserve.listenclose();
    for (int i = 0; i < vthid.size(); ++i)
    {
        pthread_cancel(vthid[i]);
    }
    logfile.Write("服务端关闭，主进程退出\n");
    exit(0);
}