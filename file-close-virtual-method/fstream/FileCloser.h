// Juliet CWE675_Duplicate_Operations_on_Resource__open_81.h

#include <stdio.h>
#include <fstream>

namespace test { 
 
class FileCloserBase
{  
public:  
    virtual void action(std::ofstream * fs) {};  
};  
 
class FileCloserSubclass : public FileCloserBase
{  
public:  
    void action(std::ofstream * fs);  
};  
 
} 
