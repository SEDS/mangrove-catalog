// Juliet CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_rand_45.c
// Original structure: alloc-using-global-var

// #################################################################
// ## Variant: alloc-using-global-var_02
// ## CHANGE: Use local variable
// #################################################################

#include <stdio.h>
#include <stdlib.h>

static void goodG2BSink()
{
    // CHANGE: Use a local variable instead of passing data using a global variable.
    int data = 20;
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
    // Tool B FP: none
    // Tool A FP: none
    printf("%d\n", intPointer[0]);
    free(intPointer);
}

int main(void)
{
    goodG2BSink();
    return 0;
}