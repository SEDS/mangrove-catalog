// Juliet CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_14.cpp
// Original structure: clear-list

// #################################################################
// ## Variant: clear-list_01
// ## CHANGE: No call to clear the list
// #################################################################

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
            // CHANGE: Removed call to clear the list.
        }
        // Tool C FP: none
        // Tool B FP: none
        // Tool A FP: none
        printf("data: %d\n", *i);
    }
    return 0;
}