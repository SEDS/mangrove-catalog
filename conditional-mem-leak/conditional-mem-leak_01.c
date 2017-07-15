// Juliet CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_fixed_string_05.c
// Original structure: conditional-mem-leak

// #################################################################
// ## Variant: conditional-mem-leak_01
// ## CHANGE: Made global variable `const`
// #################################################################

#include <stdlib.h>

// CHANGE: Made global variable constant.
static const int staticTrue = 1;

int main(void)
{
    char * data = (char *)malloc(10*sizeof(char));
    if(staticTrue)
    {
        free(data);
    }
    // Tool C FP: none
    // Tool B FP: none
    // Tool A FP: none

    // Note: Adding a return statement here causes the Tool A FP to go away.
}