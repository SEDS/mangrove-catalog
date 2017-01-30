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

    // Tool C error: Buffer Overrun. This code reads past the end of the buffer pointed to by 'data'.
    //   - 'data' evaluates to '&dataBadBuffer'.
    //   - The first byte read is at offset 4 from the beginning of the buffer pointed to by 'data', whose capacity is 4 bytes.
    //       - The offset exceeds the capacity.
    //   - The overrun occurs in stack memory.
    // Tool B error: (warning) Function call argument is an uninitialized value
    // Tool A error: none
    printf("int: %d\n", (reinterpret_cast<TwoIntsClass *>(data))->intTwo);
    return 0;
}