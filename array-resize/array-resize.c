// Juliet CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_console_42.c
// Structure: array-resize

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 5

void helper(char * data) 
{
    // If `dataLen` evalutes to SIZE-1, the warning will be a TP.
    size_t dataLen = strlen(data);
    if (fgets(data+dataLen, (int)(SIZE-dataLen), stdin) != NULL)
    {
        // Tool C FP: Useless Assignment. This code assigns the variable the same value it already had.
        // Tool B FP: none
        // Tool A FP: none
        dataLen = strlen(data);
    }
}

int main(void)
{
    char * data;
    data = (char *)malloc(SIZE*sizeof(char));
    data[0] = '\0';

    helper(data);

    free(data);
    return 0;
}