// Juliet CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_14.cpp

#include <list>
#include <stdio.h>

int main(void)
{
    std::list<int> data;
    data.push_back(7);

    std::list<int> ::iterator i;
    i = data.begin();

    data.clear();

    // ERROR: Attempt to read an element from the list after clearing it.
    // Static Code Analysis Tool TP: Use after free. The memory pointed to by *i was freed...and is read from here.
    // Static Code Analysis Tool TP: none
    // Static Code Analysis Tool TP: none
    printf("data: %d\n", *i);

    return 0;
}