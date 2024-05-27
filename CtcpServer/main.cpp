#include "CtcpServe.h"
#include <signal.h>
#include "_freecplus.h"
using namespace std;

void FATHEXIT(int sig);
void CHLDEXIT(int sig);

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
    if (fork() > 0)
        exit(0);
    signal(SIGINT, FATHEXIT);
    signal(SIGTERM, FATHEXIT);
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
        if (ctcpserve.accept() == false)
        {
            logfile.Write("accept() \n");
            return -1;
        }
        // 关闭多余的socket
        if (fork() > 0)
        {
            ctcpserve.clientclose();
            continue;
        }
        signal(SIGINT, CHLDEXIT);
        signal(SIGTERM, CHLDEXIT);
        ctcpserve.listenclose();
        logfile.Write("客户端已连接 \n");
        string buffer;
        while (true)
        {
            if (ctcpserve.recv(buffer, 1024) == false)
            {
                logfile.Write("recv() \n");
                break;
            }
            logfile.Write("接收：%s\n", buffer.c_str());
            buffer = "ok";
            if (ctcpserve.send(buffer) == false)
            {
                logfile.Write("send() \n");
                break;
            }
            logfile.Write("发送：%s\n", buffer.c_str());
        }
    }
}

void FATHEXIT(int sig)
{
    if (sig > 0)
    {
        signal(sig, SIG_IGN);
        signal(SIGINT, SIG_IGN);
        signal(SIGTERM, SIG_IGN);
        logfile.Write("catching the signal \n");
    }
    kill(0, 15);
    logfile.Write("父进程退出 \n");
    // 编写善后代码（释放资源，提交或回滚事物）
    exit(0);
}

void CHLDEXIT(int sig)
{
    if (sig > 0)
    {
        signal(sig, SIG_IGN);
        signal(SIGINT, SIG_IGN);
        signal(SIGTERM, SIG_IGN);
        logfile.Write("catching the signal \n");
    }
    logfile.Write("子进程退出 \n");
    // 编写善后代码（释放资源，提交或回滚事物）
    exit(0);
}