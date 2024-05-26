#include "mkdir.h"
// 如果输入为文件，第二个参数为true，为文件夹则为false
bool MKDIR(const char *filePath, bool isFile)
{
    // 存放文件路径
    char strPathName[301];
    int PathLen = strlen(filePath);
    for (int i = 1; i < PathLen; ++i)
    {
        if (filePath[i] != '/')
            continue;
        memset(strPathName, 0, sizeof(strPathName));
        // 将filePath的i个字符复制到strPathName中
        strncpy(strPathName, filePath, i);
        // access：F_OK判断目录是否存在，存在返回0
        if (access(strPathName, F_OK) == 0)
            continue;
        // 创建目录，0755为权限
        if (mkdir(strPathName, 0755) != 0)
            return false;
    }
    // isFile为false时，将最后一个目录创建
    if (isFile == false)
    {
        if (access(filePath, F_OK) != 0)
        {
            if (mkdir(filePath, 0755) != 0)
                return false;
        }
    }
    return true;
}
