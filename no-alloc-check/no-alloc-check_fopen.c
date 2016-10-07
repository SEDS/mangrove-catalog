// Juliet CWE675_Duplicate_Operations_on_Resource__fopen_18.c
// Structure: no-alloc-check_fopen (potentially a FP)

#include <stdio.h>

int main(void)
{
    // Static Code Analysis Tool note: fopen() returns NULL.
    FILE * data = fopen("myfile.txt", "w+");

    // Static Code Analysis Tool warning: Null Pointer Dereference. The body of fclose() dereferences 'data', but it is NULL.
    // Static Code Analysis Tool warning: none
    // Static Code Analysis Tool warning: none
    fclose(data);
    return 0;
}