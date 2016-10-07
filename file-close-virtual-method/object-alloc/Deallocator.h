#include "DataClass.h"
#include <stdio.h>

namespace test { 
 
class DeallocatorBase
{  
public:
    virtual void dealloc(DataClass * dataObj) {}
};  
 
class DeallocatorSubclass : public DeallocatorBase
{  
public:  
    void dealloc(DataClass * dataObj);
};  
 
} 
