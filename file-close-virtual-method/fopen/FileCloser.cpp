// Juliet CWE675_Duplicate_Operations_on_Resource__open_81_goodG2B.cpp

#include "FileCloser.h"
#include <stdlib.h>

namespace test { 

void FileCloserSubclass::action(FILE * fp)
{  
    // If comment out this line, Tool C does NOT flag a warning (in that case it would be a TP)...strange!
    // If using the plain `open()` function, Tool C would flag an error.
    fclose(fp);
}
  
}
