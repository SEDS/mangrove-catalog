// Juliet CWE675_Duplicate_Operations_on_Resource__open_81.h

#include <unistd.h>  
#include <stdio.h>

namespace test { 
 
class FileCloser
{  
public:  
    virtual void action(int data);  
};  
 
} 
