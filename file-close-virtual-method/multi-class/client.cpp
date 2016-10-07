#include "A.h"
#include "B.h"
#include "C.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>


void createFile(void)
{  
    int data = open("GoodSource_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    B * closeObj = new C();
 
    closeObj->action(data);  
    delete closeObj;  
}


int main(void) {
    createFile();
    return 0;
}
