// Juliet s02/CWE590_Free_Memory_Not_on_Heap__delete_class_alloca_11.cpp
// Original structure: conditional-null-ptr-external-function

// #################################################################
// ## Variant: conditional-null-ptr-external-function_01
// ## CHANGE: Function defined locally
// #################################################################

#include <stdio.h>
#include <stdlib.h>

// CHANGE: Define function locally (within this file) instead of in external file.
int globalReturnsTrue() 
{
    return 1;
}

int main(void)
{
    int * myint = NULL;
    if(globalReturnsTrue())
    {
        myint = (int *)malloc(sizeof(int));
        *myint = 5;
    }

    // Static Code Analysis Tool FP: none
    // Static Code Analysis Tool FP: Possible null pointer dereference: 'myint'
    printf("int: %d\n", *myint);
    
    free(myint);
    return 0;
}