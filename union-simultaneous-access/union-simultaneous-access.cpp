// Juliet CWE476_NULL_Pointer_Dereference__class_34.cpp
// Structure: union-simultaneous-access

#include <stdio.h>

class ClassType 
{
    public:
        int num;
};

typedef union
{
    ClassType * firstMember;
    ClassType * secondMember;
} unionType;


int main(void)
{
    unionType myUnion;
    ClassType * myClass = new ClassType();
    myUnion.firstMember = myClass;

    // Tool C FP: none
    // Tool B FP: (warning) Potential leak of memory pointed to by 'myUnion.firstMember'
    // Tool A FP: none
    ClassType * myClass2 = myUnion.secondMember;
    delete myClass2;
    return 0;
}