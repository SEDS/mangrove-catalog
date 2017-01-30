// Juliet CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_45.c
// Original structure: alloc-using-global-var

// #################################################################
// ## Variant: alloc-using-global-var_03
// ## CHANGE: Global variable initialized at global scope
// #################################################################

#include <stdio.h>
#include <stdlib.h>

// CHANGE: Initialize global variable here instead of in main().
static int staticGlobal = 20;

static void goodG2BSink()
{
    int data = staticGlobal;
    size_t i;
    int *intPointer;
    /* POTENTIAL FLAW: if data * sizeof(int) > SIZE_MAX, overflows to a small value
     * so that the for loop doing the initialization causes a buffer overflow */
    intPointer = (int*)malloc(data * sizeof(int));
    for (i = 0; i < (size_t)data; i++)
    {
        intPointer[i] = 7; /* Potentially writes beyond the boundary of intPointer */
    }
    // Tool C FP: none
    // Tool B FP: (warning) Function call argument is an uninitialized value
    // Tool A FP: none
    printf("%d\n", intPointer[0]);
    free(intPointer);
}

int main(void)
{   
    goodG2BSink();
    return 0;
}
