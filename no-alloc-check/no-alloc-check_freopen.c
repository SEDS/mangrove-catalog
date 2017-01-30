// Juliet CWE675_Duplicate_Operations_on_Resource__freopen_43.cpp
// Structure: no-alloc-check_freopen (potentially a FP)

#include <stdio.h>

int main(void)
{
    // Tool C note: freopen() returns NULL.
    FILE * data = freopen("myfile.txt", "w+", stdin);

    // Tool C warning: Null Pointer Dereference. The body of fclose() dereferences 'data', but it is NULL.
    // Tool B warning: none
    // Tool A warning: none
    fclose(data);
    return 0;
}