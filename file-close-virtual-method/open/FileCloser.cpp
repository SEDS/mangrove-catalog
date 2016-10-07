// Juliet CWE675_Duplicate_Operations_on_Resource__open_81_goodG2B.cpp
// Structure: file-close-virtual-method

#include "FileCloser.h"
#include <unistd.h>
 
namespace test { 

void FileCloserSubclass::action(int fildes)  
{  
    close(fildes);  
}
  
}