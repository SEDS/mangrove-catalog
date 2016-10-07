// Juliet CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__class_01.cpp
// Original structure: lack-of-specificity/bad-cast-argument

// #################################################################
// ## Variant: bad-cast-argument_01
// ## CHANGE: Corrected the bad cast
// #################################################################

#include <stdio.h>

class TwoIntsClass 
{
    public:
        int intOne;
        int intTwo;
};

int main(void)
{
    // CHANGE: Use an instance of the class that will be casted to (instead of using an integer).
    TwoIntsClass dataGoodBuffer;
    dataGoodBuffer.intOne = 5;
    dataGoodBuffer.intTwo = 7;

    void * data = &dataGoodBuffer;

    // Static Code Analysis Tool error: none
    // Static Code Analysis Tool error: none
    // Static Code Analysis Tool error: none
    printf("int: %d\n", (reinterpret_cast<TwoIntsClass *>(data))->intTwo);
    return 0;
}