#include "CtcpClient.h"

using namespace std;

int main(int argc,char* argv[]){
    if(argc!=3){
        cout<<"服务端ip：172.20.12.156,服务端端口：5005"<<endl;
        return -1;
    }
    // string str1="172.20.12.156";

    CtcpClient ctcpclient;
    if(ctcpclient.connect(argv[1],atoi(argv[2]))==false){
        perror("connect()");
        return -1;
    }

    // if(ctcpclient.connect(str1,5005)==false){
    //     perror("connect()");
    //     return -1;
    // }
    string buffer;
    for(int i=0;i<100;++i){
        buffer="这是第"+to_string(i+1)+"个请求";
        if(ctcpclient.send(buffer)==false){
            perror("send()");
            break;
        }
        cout<<"发送："<<buffer<<endl;
        if(ctcpclient.recv(buffer,1024)==false){
            perror("recv");
            break;
        }
        cout<<"接收："<<buffer<<endl;
        sleep(1);
    }
}