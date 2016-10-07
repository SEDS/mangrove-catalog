// Juliet CWE675_Duplicate_Operations_on_Resource__open_81_goodG2B.cpp

#include "FileCloser.h"
#include <fstream>
 
namespace test { 

void FileCloserSubclass::action(std::ofstream * fs)  
{  
    fs->close();
}
  
}
