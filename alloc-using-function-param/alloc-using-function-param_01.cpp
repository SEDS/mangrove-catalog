// Juliet CWE680_Integer_Overflow_to_Buffer_Overflow__new_listen_socket_51b.cpp
// Original structure: alloc-using-function-param

// #################################################################
// ## Variant: alloc-using-function-param_01
// ## CHANGE: Main() in same function
// #################################################################

#include <stdio.h>

void good(int data)
{
    size_t dataBytes = data * sizeof(int); /* sizeof array in bytes */
    int * intPointer = (int*)new char[dataBytes];
    for (size_t i = 0; i < (size_t)data; i++)
    {
        intPointer[i] = 5; /* may write beyond limit of intPointer if integer overflow occurred above */
    }
    // Tool C FP: Uninitialized Variable. *intPointer was not initialized.
    // Tool B FP: none
    // Tool A FP: none
    printf("int: %d\n", intPointer[0]);
    delete [] intPointer;
}

// CHANGE: Move main() function to same file.
int main(void) {
    int data = 20;
    good(data);
    return 0;
}