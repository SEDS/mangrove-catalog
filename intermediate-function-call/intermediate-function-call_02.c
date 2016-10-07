// Juliet CWE476_NULL_Pointer_Dereference__char_07.c
// Original structure: intermediate-function-call

// #################################################################
// ## Variant: intermediate-function-call_02
// ## CHANGE: Local function call
// #################################################################

#include <stdio.h>

static int staticFive = 5;

// Same definition as the printLine() function defined externally.
void printLineLocal(const char * line)
{
    if(line != NULL) 
    {
        printf("%s\n", line);
    }
}

int main(void)
{
    char * data;
    if(staticFive!=5)
    {
        // CHANGE: Replaced external function with local function call that does the same thing. 
        printLineLocal("shouldn't print");
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