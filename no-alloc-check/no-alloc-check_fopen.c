// Juliet CWE675_Duplicate_Operations_on_Resource__fopen_18.c
// Structure: no-alloc-check_fopen (potentially a FP)

#include <stdio.h>

int main(void)
{
    // Tool C note: fopen() returns NULL.
    FILE * data = fopen("myfile.txt", "w+");

    // Tool C warning: Null Pointer Dereference. The body of fclose() dereferences 'data', but it is NULL.
    // Tool B warning: none
    // Tool A warning: none
    fclose(data);
    return 0;
}