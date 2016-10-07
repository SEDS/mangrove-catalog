// Juliet CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_fixed_string_05.c
// Structure: conditional-mem-leak

#include <stdlib.h>

static int staticTrue = 1;

int main(void)
{
    char * data = (char *)malloc(10*sizeof(char));
    if(staticTrue)
    {
        free(data);
    }
    // Static Code Analysis Tool FP: none
    // Static Code Analysis Tool FP: (warning) Potential leak of memory pointed to by 'data'
    // Static Code Analysis Tool FP: (error) Memory leak: data
    
    // Note: Adding a return statement here causes the Static Code Analysis Tool FP to go away.
}