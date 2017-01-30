// Juliet CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__class_33.cpp
// Original structure: ref-ptr-read

// #################################################################
// ## Variant: ref-ptr-read_02
// ## CHANGE: Integer data allocated on heap
// #################################################################

#include <stdio.h>

int main(void)
{
    // CHANGE: Use integer data type instead of char.
    int * data;
    int * &dataRef = data;

    // CHANGE: Data allocated on stack
    
    // Tool C FP: none
    // Tool B FP: none
    // Tool A FP: none
    data = new int(15);
    
    // Tool A FP: (error) Memory is allocated but not initialized: data [unrelated to ref-ptr-read FP structure]
    printf("int: %d\n", *dataRef);

    delete data;
    return 0;
}