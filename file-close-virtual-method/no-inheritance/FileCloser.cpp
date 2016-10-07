// Juliet CWE675_Duplicate_Operations_on_Resource__open_81_goodG2B.cpp

#include "FileCloser.h"
#include <unistd.h>
#include <stdio.h>
 
namespace test { 

void FileCloser::action(int data)  
{ 
    close(data);  
}
  
}
