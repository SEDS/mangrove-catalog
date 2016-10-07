#ifndef __C__
#define __C__

#include "B.h"
#include <unistd.h>  

class C : public B
{  
public:  
    void action(int data);  
};

#endif
