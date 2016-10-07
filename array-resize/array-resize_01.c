// Juliet CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_console_42.c
// Original structure: array-resize

// #################################################################
// ## Variant: array-resize_01
// ## CHANGE: Allocate and initialize array inside helper function
// #################################################################

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 5

void helper() 
{
    // CHANGE: Allocate and initialize the array inside the helper function (instead of in main function).
    char * data;
    data = (char *)malloc(SIZE*sizeof(char));
    data[0] = '\0';

    size_t dataLen = strlen(data);
    if (fgets(data+dataLen, (int)(SIZE-dataLen), stdin) != NULL)
    {
        // Static Code Analysis Tool FP: none
        // Static Code Analysis Tool FP: none
        // Static Code Analysis Tool FP: none
        dataLen = strlen(data);
    }
    free(data);
}

int main(void)
{
    helper();
    return 0;
}