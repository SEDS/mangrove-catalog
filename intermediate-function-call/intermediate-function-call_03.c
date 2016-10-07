// Juliet CWE476_NULL_Pointer_Dereference__char_07.c
// Original structure: intermediate-function-call

// #################################################################
// ## Variant: intermediate-function-call_03
// ## CHANGE: Call to printf() instead
// #################################################################

#include <stdio.h>

static int staticFive = 5;

int main(void)
{
    char * data;
    if(staticFive!=5)
    {
        // CHANGE: Replaced external function with call to printf() from stdio.h.
        printf("shouldn't print");
    }
    else
    {
        data = "Good";
    }

    if(staticFive==5)
    {
        // Static Code Analysis Tool FP: none
        // Static Code Analysis Tool FP: none
        // Static Code Analysis Tool FP: none
        printf("%02x\n", data[0]);
    }
    return 0;
}