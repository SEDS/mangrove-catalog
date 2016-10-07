#include "Deallocator.h"
#include "DataClass.h"
 
namespace test { 

void DeallocatorSubclass::dealloc(DataClass * dataObj)  
{  
    delete dataObj;  
}
  
}
