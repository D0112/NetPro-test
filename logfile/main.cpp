#include "mkdir.h"
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    cout << "start" << endl;

    bool flag = (strcmp(argv[2], "true") == 0);

    MKDIR(argv[1], flag);
    return 0;
}