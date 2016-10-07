// Juliet CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_console_62a.cpp
// Structure: array-input-conditional

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SEARCH_CHAR 'S'
#define SIZE 5

// Note: It makes no difference on the SCA tool result whether the `data` parameter is a reference or not.
void helper(char * &data)
{
    // Read from standard in and append to array.
    size_t dataLen = strlen(data);
    fgets(data+dataLen, (int)(SIZE-dataLen), stdin);
}

int main(void)
{
    char * data = (char *)malloc(SIZE*sizeof(char));
    data[0] = '\0';

    helper(data);

    size_t i;
    for (i=0; i < strlen(data); i++)
    {
        if (data[i] == SEARCH_CHAR)
        {
            // Static Code Analysis Tool FP: Unreachable Call. The highlighted code will not execute under any circumstances.
            // Static Code Analysis Tool FP: none
            // Static Code Analysis Tool FP: none
            printf("We have a match!\n");
            break;
        }
    }
    free(data);
    return 0;
}