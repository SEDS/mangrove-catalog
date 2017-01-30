// Juliet CWE415_Double_Free__malloc_free_char_32.c
// Original structure: lack-of-specificity/dereference-non-ptr

// #################################################################
// ## Variant: dereference-non-ptr_02
// ## CHANGE: Assign allocated, non-dangling pointer
// #################################################################

#include <stdlib.h>

int main(void)
{
    char * data;
    char * *dataPtr = &data;

    data = (char *)malloc(100*sizeof(char));
    free(data);

    char * something = (char *)malloc(sizeof(char));
    *something = 'a';

    // CHANGE: Use allocated, non-dangling pointer on RHS of assignment.

    // Tool C FP: none
    // Tool B FP: none
    // Tool A FP: none
    *dataPtr = something;

    free(something);
    return 0;
}