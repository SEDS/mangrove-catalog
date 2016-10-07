// Juliet CWE476_NULL_Pointer_Dereference__class_11.cpp
// Structure: conditional-uninit-var-external-function

// *** REQUIRES TEST CASE SUPPORT FILES ***

#include "std_testcase.h"
#include <stdio.h>

int main(void)
{
    TwoIntsClass * data;
    if (globalReturnsTrue())
    {
        data = new TwoIntsClass;
        data->intOne = 5;
    }
    // Static Code Analysis Tool FP: none
    // Static Code Analysis Tool FP: Dereference of undefined pointer value
    // Static Code Analysis Tool FP: Uninitialized variable: data
    printf("data: %d\n", data->intOne);
    delete data;
    return 0;
}