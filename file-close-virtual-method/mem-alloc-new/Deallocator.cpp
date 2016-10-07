#include "Deallocator.h"
 
namespace test { 

void DeallocatorSubclass::dealloc(char * myStr)  
{  
    delete [] myStr;  
}
  
}
