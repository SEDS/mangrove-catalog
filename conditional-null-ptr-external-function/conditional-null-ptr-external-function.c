// Juliet s02/CWE590_Free_Memory_Not_on_Heap__delete_class_alloca_11.cpp
// Structure: conditional-null-ptr-external-function

// *** REQUIRES TEST CASE SUPPORT FILES ***

#include "std_testcase.h"

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int * myint = NULL;
    if(globalReturnsTrue())
    {
        myint = (int *)malloc(sizeof(int));
        *myint = 5;
    }

    // Tool C FP: none
    // Tool B FP: (warning) Dereference of null pointer (loaded from variable 'myint')
    // Tool A FP: (error) Possible null pointer dereference: 'myint'
    printf("int: %d\n", *myint);
    
    free(myint);
    return 0;
}