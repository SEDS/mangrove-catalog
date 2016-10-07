// Juliet CWE680_Integer_Overflow_to_Buffer_Overflow__new_listen_socket_51b.cpp
// Structure: alloc-using-function-param

#include <stdio.h>

void good(int data)
{
    size_t dataBytes = data * sizeof(int); /* sizeof array in bytes */
    int * intPointer = (int*)new char[dataBytes];
    for (size_t i = 0; i < (size_t)data; i++)
    {
        intPointer[i] = 5; /* may write beyond limit of intPointer if integer overflow occurred above */
    }
    // Static Code Analysis Tool FP: Uninitialized Variable. *intPointer was not initialized.
    // Static Code Analysis Tool FP: none
    // Static Code Analysis Tool FP: none
    printf("int: %d\n", intPointer[0]);
    delete [] intPointer;
}
