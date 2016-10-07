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

    // Static Code Analysis Tool FP: none
    // Static Code Analysis Tool FP: Potential leak of memory pointed to by 'myUnion.firstMember'
    // Static Code Analysis Tool FP: none
    ClassType * myClass2 = myUnion.secondMember;
    delete myClass2;
    return 0;
}