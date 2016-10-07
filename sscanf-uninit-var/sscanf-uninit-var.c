// Juliet testcasesupport/io.c
// Structure: sscanf-uninit-var.c

// Code below is based off of an example at http://www.tutorialspoint.com/c_standard_library/c_function_sscanf.htm,
// but the underlying structure also appears in the file `io.c` in Juliet.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   int myInt;
   char str[10];
   
   strcpy(str, "7");
   sscanf(str, "%d", &myInt);

   // Static Code Analysis Tool FP: Uninitialized Variable. 'myInt' was not initialized.
   // Static Code Analysis Tool FP: none
   // Static Code Analysis Tool FP: none
   printf("%d\n", myInt);
    
   return 0;
}