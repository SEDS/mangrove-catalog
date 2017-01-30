// Juliet CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_environment_06.c
// Structure: buffer-store-strncat

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

int main(void)
{
    char * data = (char *)malloc(SIZE*sizeof(char));
    data[0] = '\0';
    size_t dataLen = strlen(data);

    char * environment = getenv("USER");

    if (environment != NULL)
    {
        // (Side note: For `strncat` the length argument does NOT include the null character--that is always added regardless.)

        // Tool C FP: Tainted Buffer Access. This code could write past the end of the buffer pointed to by 'data'.
        // Tool B FP: none
        // Tool A FP: none
        strncat(data+dataLen, environment, SIZE-dataLen-1);
    }

    free(data);
    return 0;
}