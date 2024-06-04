#include "CtcpClient.h"
#include "_freecplus.h"
using namespace std;
CLogFile logfile;
int main(int argc, char *argv[])
{
    if (logfile.Open("./logfile") == false)
    {
        cout << "logfile.Open is Wrong" << endl;
    }

    if (argc != 3)
    {
        logfile.Write("服务端ip：172.20.12.156,服务端端口：5005 \n");
        return -1;
    }
    logfile.Write("LOG Successfully \n");

    // string str1="172.20.12.156";

    CtcpClient ctcpclient;
    if (ctcpclient.connect(argv[1], atoi(argv[2])) == false)
    {
        logfile.Write("connect() \n");
        return -1;
    }

    // if(ctcpclient.connect(str1,5005)==false){
    //     perror("connect()");
    //     return -1;
    // }
    string buffer;
    for (int i = 0; i < 3; ++i)
    {
        buffer = "This is" + to_string(i + 1) + "th Request";
        if (ctcpclient.send(buffer) == false)
        {
            logfile.Write("send() \n");
            break;
        }
        logfile.Write("发送： %s\n", buffer.c_str());
        if (ctcpclient.recv(buffer, 1024) == false)
        {
            logfile.Write("recv() \n");
            break;
        }
        logfile.Write("接收： %s\n", buffer.c_str());
        sleep(1);
    }
}