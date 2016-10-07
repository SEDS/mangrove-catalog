// Juliet CWE476_NULL_Pointer_Dereference__char_33.cpp
// Structure: ref-ptr-read

#include <stdio.h>

int main(void)
{
    char * data;
    char * &dataRef = data;

    // Static Code Analysis Tool FP: none
    // Static Code Analysis Tool FP: Value stored to 'data' is never read
    // Static Code Analysis Tool FP: none
    data = "Good";
    printf("%c\n", dataRef[0]);
    return 0;
}