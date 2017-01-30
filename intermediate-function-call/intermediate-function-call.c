// Juliet CWE476_NULL_Pointer_Dereference__char_07.c
// Structure: intermediate-function-call

// *** REQUIRES TEST CASE SUPPORT FILES ***

#include "std_testcase.h"
#include <stdio.h>

static int staticFive = 5;

int main(void)
{
    char * data;
    if(staticFive!=5)
    {
        // This function call must be here for Tool B to give a FP.
        // Tool B assumes this function sets staticFive to 5.
        printLine("shouldn't print");
    }
    else
    {
        data = "Good";
    }

    if(staticFive==5)
    {
        // Tool C FP: none
        // Tool B FP: (warning) Dereference of undefined pointer value
        // Tool A FP: none
        printf("%02x\n", data[0]);
    }
    return 0;
}