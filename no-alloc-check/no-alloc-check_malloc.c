// Juliet CWE416_Use_After_Free__malloc_free_struct_18.c
// Structure: no-alloc-check_malloc (potentially a FP)

#include <stdlib.h>

int main(void)
{
    // Tool C note: malloc() returns NULL.
    char * data = (char *)malloc(sizeof(char));

    // Tool C warning: Null Pointer Dereference. 'Data' is dereferenced here, but it is NULL.
    // Tool B warning: none
    // Tool A warning: none
    *data = 'a';
    free(data);
    return 0;
}