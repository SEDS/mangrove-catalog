// Juliet CWE675_Duplicate_Operations_on_Resource__open_81a.cpp
// Structure: file-close-virtual-method

#include "FileCloser.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>

namespace test {
 
void createFile(void)
{  
    // Tool C FP: Leak
    int fildes = open("file.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    FileCloserBase * fileCloser = new FileCloserSubclass();
 
    fileCloser->action(fildes);  
    delete fileCloser;  
}
// Tool C event: 'fildes' has gone out of scope and no longer
// references the resource of interest.
}

int main(void) {
    test::createFile();
    return 0;
}