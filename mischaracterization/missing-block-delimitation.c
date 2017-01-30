// Juliet CWE483_Incorrect_Block_Delimitation__if_without_braces_multiple_lines_01.c

#include <stdlib.h>
#include <stdio.h>

int main(void)
{ 
    int x,y;

    x = (rand() % 3);

    // Misleading Tool B warning: (warning) Value stored to 'y' is never read
    // Misleading Tool A warning: none
    y = 0;
    
    // Problem: programmer forgot to delimitate the IF body with braces.
    // Without the braces, `y` is assigned the value 1, overwriting is previous value 0.
    if (x == 0)
        printf("x == 0");
        y = 1;
        
    if (y)
    {
        printf("x was 0\n");
    }
}