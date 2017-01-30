// Juliet CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__class_09.cpp
// Original structure: conditional-uninit-var-external-var

// #################################################################
// ## Variant: conditional-uninit-var-external-var_01
// ## CHANGE: Condition variable defined within this file
// #################################################################

#include <stdio.h>

// CHANGE: Define the variable within this file instead of externally.
const int GLOBAL_CONST_TRUE = 1;

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
    // Tool B FP: none
    // Tool A FP: none
    printf("int: %d\n", *intPtr);
    return 0;
}