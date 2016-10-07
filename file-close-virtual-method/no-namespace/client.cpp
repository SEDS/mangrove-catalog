#include "FileCloser.h"
#include <fcntl.h>
#include <stdio.h>

using namespace std;

int main(void)
{  
    int data = open("GoodSource_open.txt", O_RDWR|O_CREAT);  
    FileCloserBase * baseObj = new FileCloserSubclass();
 
    baseObj->action(data);  
    delete baseObj;
    return 0;
}
