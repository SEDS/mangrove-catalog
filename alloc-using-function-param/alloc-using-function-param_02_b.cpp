// Juliet CWE680_Integer_Overflow_to_Buffer_Overflow__new_listen_socket_51b.cpp
// Original structure: alloc-using-function-param

// #################################################################
// ## Variant: alloc-using-function-param_02
// ## CHANGE: Size is set in function
// #################################################################

#include <stdio.h>

void good(int data)
{
    // CHANGE: Size is set locally in the same function.
    data = 20;
    size_t dataBytes = data * sizeof(int); /* sizeof array in bytes */
    int * intPointer = (int*)new char[dataBytes];
    for (size_t i = 0; i < (size_t)data; i++)
    {
        intPointer[i] = 5; /* may write beyond limit of intPointer if integer overflow occurred above */
    }
    // Tool C FP: none
    // Tool B FP: none
    // Tool A FP: none
    printf("int: %d\n", intPointer[0]);
    delete [] intPointer;
}
