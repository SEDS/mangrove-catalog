// Juliet CWE675_Duplicate_Operations_on_Resource__open_81a.cpp

#include "FileCloser.h"
#include <stdio.h>
#include <fstream>
#include <stdlib.h>

namespace test {
 
void createFile(void)
{  
    std::ofstream fs;
    fs.open("myfile.txt");

    FileCloserBase * closeObj = new FileCloserSubclass();
 
    closeObj->action(&fs); 
    delete closeObj;
}

}  


using namespace test;

int main(void) {
    createFile();
    return 0;
}
