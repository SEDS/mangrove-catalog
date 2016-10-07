// Juliet CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_file_01.c
// Structure: null-array-access

#include <stdlib.h>
#include <string.h>

int main(void)
{
    char * data = (char *)malloc(100*sizeof(char));
    data[0] = '\0';

    size_t i;
    for (i=0; i < strlen(data); i++)
    {
        // Simplification from Juliet: We simply assign a value from `data` instead of using it in a comparison.
        
        // Static Code Analysis Tool FP: none
        // Static Code Analysis Tool FP: Assigned value is garbage or undefined
        // Static Code Analysis Tool FP: none
        char c = data[i];
    }
    free(data);
    return 0;
}