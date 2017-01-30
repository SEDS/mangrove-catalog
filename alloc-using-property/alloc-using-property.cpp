// Juliet CWE680_Integer_Overflow_to_Buffer_Overflow__new_listen_socket_84_goodG2B.cpp
// Structure: alloc-using-property

#include "alloc-using-property.h"
#include <stdio.h>

AllocUsingProperty::AllocUsingProperty()
{
    data = 20;
}

AllocUsingProperty::~AllocUsingProperty()
{
    int i;
    size_t dataBytes = data * sizeof(int); /* sizeof array in bytes */
    int * intPointer = (int*)new char[dataBytes];
    for (i = 0; i < data; i++)
    {
        intPointer[i] = 7;
    }

    // Tool C FP: Uninitialized variable. *intPointer was not initialized
    // Tool B FP: none
    // Tool A: none
    printf("int: %d\n", intPointer[0]);
    delete [] intPointer;
}