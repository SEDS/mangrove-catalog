#include <unistd.h>  
#include <stdio.h>

class FileCloserBase
{  
public:  
    virtual void action(int data) {  
        printf("base class method called\n");  
    };  
};  
 
class FileCloserSubclass : public FileCloserBase
{  
public:  
    void action(int data);  
};  
