// Juliet CWE481_Assigning_Instead_of_Comparing__basic_01.c

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    {
        // Misleading Static Code Analysis Tool warning: Value stored to 'intRand' during its initialization is never read
        // Misleading Static Code Analysis Tool warning: Variable 'intRand' is assigned a value that is never used.
        int intRand = rand();

        // Problem: use of `=` instead of `==` operator.
        if(intRand = 5)
        {
            printf("i was 5\n");
        }
    }
}