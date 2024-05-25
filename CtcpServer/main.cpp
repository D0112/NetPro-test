#include "CtcpServe.h"

using namespace std;

int main(int argc,char* argv[]){
    if(argc!=2){
        cout<<"服务端端口号5005"<<endl;
        return -1;
    }

    CtcpServe ctcpserve;
    if(ctcpserve.initserve(atoi(argv[1]))==false){
        perror("initserve()");
        return -1;
    }

    // if(ctcpserve.initserve(5005)==false){
    //     perror("initserve()");
    //     return -1;
    // }

    if(ctcpserve.accept()==false){
        perror("accept()");
        return -1;
    }
    cout<<"客户端已连接"<<endl;
    string buffer;
    while(true){
        if(ctcpserve.recv(buffer,1024)==false){
            perror("recv()");
            break;
        }
        cout<<"接收："<<buffer<<endl;
        buffer="ok";
        if(ctcpserve.send(buffer)==false){
            perror("send()");
            break;
        }
        cout<<"发送："<<buffer<<endl;
    }
}