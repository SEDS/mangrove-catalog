// Juliet CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__class_09.cpp
// Pattern: conditional-uninit-var-external-var

// *** REQUIRES TEST CASE SUPPORT FILES ***

#include "std_testcase.h"
#include <stdio.h>

// GLOBAL_CONST_TRUE is defined as follows in io.c
// const int GLOBAL_CONST_TRUE = 1;
// If the global variable is defined within this file (still globally), the FPs go away (for Tool B and Tool A).

int main(void)
{
    int * intPtr;
    // Simplified the data structure from a class in Juliet to an integer.
    int intVar = 7;
    if(GLOBAL_CONST_TRUE)
    {
        intPtr = &intVar;
    }

    // Tool C FP: none
    // Tool B FP: (warning) Dereference of undefined pointer value
    // Tool A FP: (error) Uninitialized variable: intPtr
    printf("int: %d\n", *intPtr);
    return 0;
}