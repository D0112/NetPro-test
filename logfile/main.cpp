#include "_freecplus.h"
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    // cout << "start" << endl;

    // bool flag = (strcmp(argv[2], "true") == 0);

    // MKDIR(argv[1], flag);

    // 获取文件的大小��1�7
    printf("size=%d\n", FileSize("/home/adminn/Desktop/project/NetPro-test/logfile/include/mkdir.h"));

    // 获取文件的时间��1�7
    char mtime[21];
    memset(mtime, 0, sizeof(mtime));
    FileMTime("/home/adminn/Desktop/project/NetPro-test/logfile/include/mkdir.h", mtime, "yyyy-mm-dd hh24:mi:ss");
    printf("mtime=%s\n", mtime); // 输出mtime=2020-01-05 13:37:29

    CLogFile logfile;
    if (logfile.Open("/home/adminn/Desktop/project/NetPro-test/logfile/logfile") == false)
    {
        cout << "logfile.Open is Wrong" << endl;
    }
    if (REMOVE("/home/adminn/Desktop/project/NetPro-test/logfile/include/test") == true)
    {
        logfile.Write("REMOVE Successfully");
    }

    return 0;
}