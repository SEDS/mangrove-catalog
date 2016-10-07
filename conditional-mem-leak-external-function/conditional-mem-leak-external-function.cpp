// Juliet CWE476_NULL_Pointer_Dereference__class_11.cpp
// Structure: conditional-mem-leak-external-function

// *** REQUIRES TEST CASE SUPPORT FILES ***

#include "std_testcase.h"

int main(void)
{
    int * data = new int;

    if (globalReturnsTrue())
    {
        delete data;
    }
    // Static Code Analysis Tool FP: none
    // Static Code Analysis Tool FP: Potential leak of memory pointed to by 'data'
    // Static Code Analysis Tool FP: Memory leak: data

    // Note: Adding a return statement here causes the Static Code Analysis Tool FP to go away.
}