#include "CtcpServe.h"
#include <signal.h>
#include "mkdir.h"
using namespace std;

void FATHEXIT(int sig);
void CHLDEXIT(int sig);

CtcpServe ctcpserve;

int main(int argc, char *argv[])

{ // 避免出现僵尸进程，并关闭全部信号
    for (int ii = 0; ii < 100; ++ii)
        signal(ii, SIG_IGN);
    if (fork() > 0)
        exit(0);
    signal(SIGINT, FATHEXIT);
    signal(SIGTERM, FATHEXIT);
    // MKDIR("/home/adminn/桌面/project/test", false);
    if (argc != 2)
    {
        cout << "服务端端口号5005" << endl;
        return -1;
    }

    if (ctcpserve.initserve(atoi(argv[1])) == false)
    {
        perror("initserve()");
        return -1;
    }

    while (true)
    {
        if (ctcpserve.accept() == false)
        {
            perror("accept():");
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
        cout << "客户端已连接" << endl;
        string buffer;
        while (true)
        {
            if (ctcpserve.recv(buffer, 1024) == false)
            {
                perror("recv()");
                break;
            }
            cout << "接收：" << buffer << endl;
            buffer = "ok";
            if (ctcpserve.send(buffer) == false)
            {
                perror("send()");
                break;
            }
            cout << "发送：" << buffer << endl;
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
        cout << "catching the signal" << sig << endl;
    }
    kill(0, 15);
    cout << "父进程退出" << endl;
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
        cout << "catching the signal" << sig << endl;
    }
    cout << "子进程退出" << endl;
    // 编写善后代码（释放资源，提交或回滚事物）
    exit(0);
}