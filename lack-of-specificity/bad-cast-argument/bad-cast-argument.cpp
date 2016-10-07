// Juliet CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__class_01.cpp
// Structure: lack-of-specificity/bad-cast-argument

#include <stdio.h>

class TwoIntsClass 
{
    public:
        int intOne;
        int intTwo;
};

int main(void)
{
    int dataBadBuffer = 100;
    void * data = &dataBadBuffer;

    // Static Code Analysis Tool error: Buffer Overrun. This code reads past the end of the buffer pointed to by 'data'.
    // Static Code Analysis Tool error: Function call argument is an uninitialized value
    // Static Code Analysis Tool error: none
    printf("int: %d\n", (reinterpret_cast<TwoIntsClass *>(data))->intTwo);
    return 0;
}