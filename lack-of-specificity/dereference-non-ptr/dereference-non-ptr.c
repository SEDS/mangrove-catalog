// Juliet CWE415_Double_Free__malloc_free_char_32.c
// Structure: lack-of-specificity/dereference-non-ptr

#include <stdlib.h>

int main(void)
{
    char * data;
    char * *dataPtr = &data;

    data = (char *)malloc(100*sizeof(char));
    free(data);

    // Static Code Analysis Tool FP: none
    // Static Code Analysis Tool FP: none
    // Static Code Analysis Tool FP: Dereferencing 'data' after it is deallocated / released
    *dataPtr = data;
    return 0;
}