// Custom code
// FP structure: one-step-allocation-initialization

#include <stdio.h>

int main(void)
{
    // NOTE: FP is flagged for all data types tested: int, char, short int, float.
    int * data = new int(7);

    // Static Code Analysis Tool FP: none
    // Static Code Analysis Tool FP: none
    // Static Code Analysis Tool FP: Memory is allocated but not initialized: data
    printf("int: %d\n", *data);

    delete data;
    return 0;
}
