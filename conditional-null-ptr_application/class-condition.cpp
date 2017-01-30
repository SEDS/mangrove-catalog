// Custom code

#include "class-condition.h"
#include <stdio.h>

// Constructor sets the variable to 1 (true), and the variable is never modified later.
// Reads of this variable will always return true.
ClassCondition::ClassCondition() 
: alwaysTrue_(1)
{}

void ClassCondition::test(void) {
	int * data;
    data = NULL;

    // A tool should be able to know that reads of this variable will always return true.
    if(this->alwaysTrue_)
    { 
        data = new int(5);
    }

    // Tool C FP: Null Pointer Dereference. 'data' is dereferenced here, but it is NULL.
    // Tool B FP: Dereference of null pointer (loaded from variable 'data')
    // Tool A FP: error: Possible null pointer dereference: data
    printf("Data: %d\n", *data);

    delete data;
}