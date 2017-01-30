// Juliet CWE680_Integer_Overflow_to_Buffer_Overflow__new_listen_socket_84_goodG2B.cpp
// Original structure: alloc-using-property

// ########################################################################
// ## Variant: alloc-using-property_01
// ## CHANGE: Set private property in function that performs allocation.
// ########################################################################

#include "alloc-using-property.h"
#include <stdio.h>

AllocUsingProperty::AllocUsingProperty()
{
    data = 20;
}

AllocUsingProperty::~AllocUsingProperty()
{
    // CHANGE: Set private property in function that performs the allocation (in addition to constructor).
    data = 20;
    int i;
    size_t dataBytes = data * sizeof(int); /* sizeof array in bytes */
    int * intPointer = (int*)new char[dataBytes];
    for (i = 0; i < data; i++)
    {
        intPointer[i] = 7;
    }

    // Tool C FP: none
    // Tool B FP: none
    // Tool A: none
    printf("int: %d\n", intPointer[0]);
    delete [] intPointer;
}