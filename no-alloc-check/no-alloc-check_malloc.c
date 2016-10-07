// Juliet CWE416_Use_After_Free__malloc_free_struct_18.c
// Structure: no-alloc-check_malloc (potentially a FP)

#include <stdlib.h>

int main(void)
{
    // Static Code Analysis Tool note: malloc() returns NULL.
    char * data = (char *)malloc(sizeof(char));

    // Static Code Analysis Tool warning: Null Pointer Dereference. 'Data' is dereferenced here, but it is NULL.
    // Static Code Analysis Tool warning: none
    // Static Code Analysis Tool warning: none
    *data = 'a';
    free(data);
    return 0;
}