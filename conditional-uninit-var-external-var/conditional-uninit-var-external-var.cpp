// Juliet CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__class_09.cpp
// Pattern: conditional-uninit-var-external-var

// *** REQUIRES TEST CASE SUPPORT FILES ***

#include "std_testcase.h"
#include <stdio.h>

// GLOBAL_CONST_TRUE is defined as follows in io.c
// const int GLOBAL_CONST_TRUE = 1;
// If the global variable is defined within this file (still globally), the FPs go away (for Static Code Analysis Tool and Static Code Analysis Tool).

int main(void)
{
    int * intPtr;
    // Simplified the data structure from a class in Juliet to an integer.
    int intVar = 7;
    if(GLOBAL_CONST_TRUE)
    {
        intPtr = &intVar;
    }

    // Static Code Analysis Tool FP: none
    // Static Code Analysis Tool FP: Dereference of undefined pointer value
    // Static Code Analysis Tool FP: Uninitialized variable: intPtr
    printf("int: %d\n", *intPtr);
    return 0;
}