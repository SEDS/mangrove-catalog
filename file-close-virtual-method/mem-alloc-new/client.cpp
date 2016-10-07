#include "Deallocator.h"
#include <stdio.h>

namespace test {
 
void createFile(void)
{  
    // Allocate array of characters to use as the resource.
    char * myStr = new char[100];
    // Deallocator object to delete the resource through a virtual method.
    DeallocatorBase * deallocObj = new DeallocatorSubclass();
 
    deallocObj->dealloc(myStr);  
    delete deallocObj;  
}
}  

using namespace test;

int main(void) {
    createFile();
    return 0;
}
