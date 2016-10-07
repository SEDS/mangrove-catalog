#include "FileCloser.h"
#include <unistd.h>
 
void FileCloserSubclass::action(int data)  
{  
    close(data);  
}
