#ifndef __B__
#define __B__

#include "A.h"
#include <unistd.h>  

class B : public A
{  
public:  
    virtual void action(int data);  
};

#endif
