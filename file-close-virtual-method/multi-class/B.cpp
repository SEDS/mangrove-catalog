#include "B.h"
#include <unistd.h>

void B::action(int data)  
{  
    close(data);  
}
