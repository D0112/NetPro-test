#include "CtcpServe.h"
#include <signal.h>
using namespace std;

int main(int argc, char *argv[])

{ // 避免僵尸进程
    signal(SIGCHLD, SIG_IGN);
    if (argc != 2)
    {
        cout << "服务端端口号5005" << endl;
        return -1;
    }

    CtcpServe ctcpserve;
    if (ctcpserve.initserve(atoi(argv[1])) == false)
    {
        perror("initserve()");
        return -1;
    }

    while (true)
    {
        if (ctcpserve.accept() == false)
        {
            perror("accept()");
            return -1;
        }
        // 关闭多余的socket
        if (fork() > 0)
        {
            ctcpserve.clientclose();
            continue;
        }
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