// Juliet CWE476_NULL_Pointer_Dereference__char_33.cpp
// Structure: ref-ptr-read

#include <stdio.h>

int main(void)
{
    char * data;
    char * &dataRef = data;

    // Tool C FP: none
    // Tool B FP: (warning) Value stored to 'data' is never read
    // Tool A FP: none
    data = "Good";
    printf("%c\n", dataRef[0]);
    return 0;
}