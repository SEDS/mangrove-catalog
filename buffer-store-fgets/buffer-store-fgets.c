// Juliet CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_console_22a.c
// Structure: buffer-store-fgets

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

int main(void)
{
    char * data = (char *)malloc(SIZE*sizeof(char));
    data[0] = '\0';
    // 'dataLen' is assigned the value 0.
    size_t dataLen = strlen(data);
    
    // Note: If 'dataLen' is removed from the fgets() arguments (both instances), Static Code Analysis Tool FP goes away.
    if (fgets(data+dataLen, (int)(SIZE-dataLen), stdin) != NULL)
    {
        dataLen = strlen(data);
        // 'dataLen' is now at most SIZE-1. Thus, 'dataLen-1' is at most SIZE-2,
        // which is in the bounds of the array (unless the index would be negative,
        // but this conditional eliminates that case.)
        if (dataLen > 0 && data[dataLen-1] == '\n')
        {
            // Static Code Analysis Tool FP: Tainted Buffer Access. This code could write past the end of the buffer pointed to by data.
            // Static Code Analysis Tool FP: none
            // Static Code Analysis Tool FP: none
            data[dataLen-1] = '\0';
        }
    }
    free(data);
    return 0;
}