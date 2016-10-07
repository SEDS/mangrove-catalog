// Juliet CWE680_Integer_Overflow_to_Buffer_Overflow__new_listen_socket_51a.cpp
// Structure: alloc-using-function-param

void good(int data);

int main(void)
{
    int data = 20; 
    good(data);
    return 0;
}
