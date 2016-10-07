#include "C.h"
#include <unistd.h>
 
void C::action(int data)  
{  
    close(data);  
}
