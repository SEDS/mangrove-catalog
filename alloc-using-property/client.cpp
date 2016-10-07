#include "alloc-using-property.h"

int main(void)
{
    AllocUsingProperty * myObject = new AllocUsingProperty();
    delete myObject;
    return 0;
}