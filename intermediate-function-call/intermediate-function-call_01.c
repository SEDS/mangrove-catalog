// Juliet CWE476_NULL_Pointer_Dereference__char_07.c
// Original structure: intermediate-function-call

// #################################################################
// ## Variant: intermediate-function-call_01
// ## CHANGE: No function call
// #################################################################

#include <stdio.h>

static int staticFive = 5;

int main(void)
{
    char * data;
    if(staticFive!=5)
    {
        // CHANGE: Removed call to externally defined function
    }
    else
    {
        data = "Good";
    }

    if(staticFive==5)
    {
        // Tool C FP: none
        // Tool B FP: none
        // Tool A FP: none
        printf("%02x\n", data[0]);
    }
    return 0;
}