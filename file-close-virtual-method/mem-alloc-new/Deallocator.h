#include <stdio.h>

namespace test { 
 
class DeallocatorBase
{  
public:
    virtual void dealloc(char * myStr) {}
};  
 
class DeallocatorSubclass : public DeallocatorBase
{  
public:  
    void dealloc(char * myStr);
};  
 
} 
