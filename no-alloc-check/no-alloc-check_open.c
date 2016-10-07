// Juliet CWE675_Duplicate_Operations_on_Resource__open_03.c
// Structure: no-alloc-check_open (potentially a FP)

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void)
{
    // Static Code Analysis Tool note: open() returns -1.
    int data = open("myfile.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);

    // Static Code Analysis Tool warning: Negative file descriptor. File descriptor argument data has value -1. 'close()' will fail when called with a negative file descriptor.
    // Static Code Analysis Tool warning: none
    // Static Code Analysis Tool warning: none
    close(data);
    return 0;
}