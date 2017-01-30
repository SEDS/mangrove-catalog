// Juliet s01/CWE121_Stack_Based_Buffer_Overflow__CWE131_loop_05.c
// Structure: conditional-null-ptr

#include <stdlib.h>

static int staticTrue = 1;

int main(void)
{
    int * data = NULL;
    if(staticTrue)
    { 
        data = (int *)malloc(10*sizeof(int));
    }

    // Tool C FP: none
    // Tool B FP: (warning) Array access (from variable 'data') results in a null pointer dereference
    // Tool A: (error) Possible null pointer dereference: data
    data[0] = 5;
    free(data);
    return 0;
}