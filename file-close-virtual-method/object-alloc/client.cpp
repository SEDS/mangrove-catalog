#include "Deallocator.h"
#include "DataClass.h"
#include <stdio.h>

namespace test {
 
void createFile(void)
{  
    // Allocate a user-defined object as the resource.
    DataClass * dataObj = new DataClass();
    // Deallocator object to delete the resource.
    DeallocatorBase * deallocObj = new DeallocatorSubclass();
 
    deallocObj->dealloc(dataObj);
    delete deallocObj;  
}
}  

using namespace test;

int main(void) {
    createFile();
    return 0;
}
