// Juliet CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_console_62a.cpp
// Parent structure: array-input-conditional

// #######################################################
// ## Variant: array-input-conditional_01
// ## CHANGE: Move call to `fgets` to main function
// #######################################################

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SEARCH_CHAR 'S'
#define SIZE 5

int main(void)
{
    char * data = (char *)malloc(SIZE*sizeof(char));
    data[0] = '\0';

    // CHANGE: Move call to `fgets()` within the main function (instead of using a helper function).
    size_t dataLen = strlen(data);
    fgets(data+dataLen, (int)(SIZE-dataLen), stdin);

    size_t i;
    for (i=0; i < strlen(data); i++)
    {
        if (data[i] == SEARCH_CHAR)
        {
            // Static Code Analysis Tool FP: none
            // Static Code Analysis Tool FP: none
            // Static Code Analysis Tool FP: none
            printf("We have a match!\n");
            break;
        }
    }
    free(data);
    return 0;
}