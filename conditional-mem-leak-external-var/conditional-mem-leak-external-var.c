// Juliet s01/CWE690_NULL_Deref_From_Return__char_malloc_09.c
// Structure: conditional-mem-leak-external-var

// *** REQUIRES TEST CASE SUPPORT FILES ***

#include "std_testcase.h"

// GLOBAL_CONST_TRUE is defined as follows in io.c
// const int GLOBAL_CONST_TRUE = 1;
// If the global variable is defined within this file (still globally), the FPs go away (for Static Code Analysis Tool and Static Code Analysis Tool).

int main(void)
{
    char * data;
    data = (char *)malloc(20*sizeof(char));
    if(GLOBAL_CONST_TRUE)
    {
    	// Static Code Analysis Tool FP: none
        // Static Code Analysis Tool FP: Potential leak of memory pointed to by 'data'
        // Static Code Analysis Tool FP: Memory leak: data
        free(data);
    }
    // Note: Adding a return statement here causes the Static Code Analysis Tool FP to go away.
}