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
        // This function call must be here for Static Code Analysis Tool to give a FP.
        // Static Code Analysis Tool assumes this function sets staticFive to 5.
        printLine("shouldn't print");
    }
    else
    {
        data = "Good";
    }

    if(staticFive==5)
    {
        // Static Code Analysis Tool FP: none
        // Static Code Analysis Tool FP: Dereference of undefined pointer value
        // Static Code Analysis Tool FP: none
        printf("%02x\n", data[0]);
    }
    return 0;
}