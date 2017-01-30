// Juliet CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_14.cpp
// Structure: clear-list

#include <list>
#include <stdio.h>

int main(void)
{
    std::list<int> data;
    data.push_back(7);

    std::list<int> ::iterator i;
    for(i = data.begin(); i != data.end(); i++)
    {
        if (!*i)
        {
            data.clear();
        }
        // Tool C FP: Use After Free. The memory pointed to by *i was freed...and is read from here.
        // Tool B FP: none
        // Tool A FP: none
        printf("data: %d\n", *i);
    }
    return 0;
}