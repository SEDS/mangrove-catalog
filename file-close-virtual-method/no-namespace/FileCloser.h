#include <unistd.h>  
#include <stdio.h>

class FileCloserBase
{  
public:  
    virtual void action(int data) {  
        printf("base class method called\n");  
    };  
    //void action(int data) {  
    //    close(data);  
    //};  
};  
 
class FileCloserSubclass : public FileCloserBase
{  
public:  
    void action(int data);  
    //void action(int data) {  
    //    printf("subclass method called\n");  
    //    close(data);  
    //};  
};  
