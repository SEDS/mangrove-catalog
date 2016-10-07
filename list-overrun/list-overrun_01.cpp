// Juliet CWE476_NULL_Pointer_Dereference__char_73b.cpp
// Original structure: list-overrun

// #################################################################
// ## Variant: list-overrun_01
// ## CHANGE: Push element from within function that reads the list
// #################################################################

#include <list>

void good(std::list<char *> dataList)
{
    // CHANGE: Push a second element onto the list from within the function that reads the list.
    char * str = "Good";
    dataList.push_back(str);

    // Static Code Analysis Tool FP: none
    // Static Code Analysis Tool FP: none
    // Static Code Analysis Tool FP: none
    char * data = dataList.back();
}

int main(void)
{
    char * str = "Good";

    std::list<char *> dataList;
    dataList.push_back(str);

    good(dataList);
    return 0;
}