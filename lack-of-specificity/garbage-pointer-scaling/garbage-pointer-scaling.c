// Juliet CWE468_Incorrect_Pointer_Scaling__char_ptr_to_int_01.c
// Pattern: lack-of-specificity/garbage-pointer-scaling

#include <stdio.h>

int main(void)
{
    int intArray[5] = { 1, 2, 3, 4, 5 };
    char * charPointer = (char *)intArray;

    // intend to read intArray[2] 
    // FLAW: sizeof() needed since pointer is a char*, not an int*

    // Tool C FP: none
    // Tool B FP: (warning) Assigned value is garbage or undefined
    // Tool A FP: none
    int toPrint = (int) (*(charPointer + 2));
    printf("intArray[2]: %d\n", toPrint);
    return 0;
}