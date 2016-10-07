#include "A.h"
#include <unistd.h>

void A::action(int data)  
{  
    close(data);  
}
