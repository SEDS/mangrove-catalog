// Juliet CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_console_42.c
// Original structure: array-resize

// ###################################################################
// ## Variant: array-resize_02
// ## CHANGE 1: Allocate and initialize array inside helper function
// ## CHANGE 2: Initialize to string of maximum length
// ###################################################################

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 5

void helper() 
{
    // CHANGE 1: Allocate and initialize the array inside the helper function (instead of in main function).
    char * data;
    data = (char *)malloc(SIZE*sizeof(char));
    // CHANGE 2: Initialize to string of maximum length within the capacity.
    strcpy(data, "abcd");

    size_t dataLen = strlen(data);
    if (fgets(data+dataLen, (int)(SIZE-dataLen), stdin) != NULL)
    {
        // Static Code Analysis Tool warning (a TP): Useless Assignment. This code assigns the variable the same value it already had.
        // Static Code Analysis Tool warning: none
        // Static Code Analysis Tool warning: none
        dataLen = strlen(data);
    }
    free(data);
}

int main(void)
{
    helper();
    return 0;
}