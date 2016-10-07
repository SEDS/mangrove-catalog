// Juliet CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_45.c
// Original structure: alloc-using-global-var

// #################################################################
// ## Variant: alloc-using-global-var_01
// ## CHANGE: Assign literal to global variable
// #################################################################

#include <stdio.h>
#include <stdlib.h>

static int staticGlobal;

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
    // Static Code Analysis Tool FP: Uninitialized Variable. *intPointer was not initialized
    // Static Code Analysis Tool FP: none
    // Static Code Analysis Tool FP: none
    printf("%d\n", intPointer[0]);
    free(intPointer);
}

int main(void)
{	
    // CHANGE: Assign literal value to global variable instead of using an alias.
    staticGlobal = 20;
    goodG2BSink();
    return 0;
}