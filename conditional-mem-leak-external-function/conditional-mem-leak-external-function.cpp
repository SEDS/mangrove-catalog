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
    // Tool C FP: none
    // Tool B FP: (warning) Potential leak of memory pointed to by 'data'
    // Tool A FP: (error) Memory leak: data

    // Note: Adding a return statement here causes the Tool A FP to go away.
}