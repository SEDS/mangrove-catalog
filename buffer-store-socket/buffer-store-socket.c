// Juliet CWE666_Operation_on_Resource_in_Wrong_Phase_of_Lifetime__listen_bind_accept_18.c
// Structure: buffer-store-socket

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1

#define TCP_PORT 27015
#define LISTEN_BACKLOG 5

#define SIZE 100

int main(void)
{
    char data[SIZE] = "";
    int recvResult;
    struct sockaddr_in service;
    int listenSocket = INVALID_SOCKET;
    int acceptSocket = INVALID_SOCKET;
    // 'dataLen' is assigned 0.
    size_t dataLen = strlen(data);
    do {
        listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (listenSocket == INVALID_SOCKET)
        {
            break;
        }
        memset(&service, 0, sizeof(service));
        service.sin_family = AF_INET;
        service.sin_port = htons(TCP_PORT);
        if (bind(listenSocket, (struct sockaddr*)&service, sizeof(service)) == SOCKET_ERROR)
        {
            break;
        }
        if (listen(listenSocket, LISTEN_BACKLOG) == SOCKET_ERROR)
        {
            break;
        }
        acceptSocket = accept(listenSocket, NULL, NULL);
        if (acceptSocket == SOCKET_ERROR)
        {
            break;
        }
        // Remember that 'dataLen' is 0.
        recvResult = recv(acceptSocket, (char *)data+dataLen, (int)(SIZE-dataLen-1), 0);
        printf("Message received. Size of message (bytes): %d\n", recvResult);

        if (recvResult == SOCKET_ERROR || recvResult == 0)
        {
            break;
        }
        // We've established that 'recvResult' must be positive at this point (see previous conditional).
        // Also, 'recvResult' can be at most 99 (see third argument of `recv` above).
        // Thus, 'recvResult' is in the bounds [1,99], which is valid for the 'data' memory block.

        // Static Code Analysis Tool FP: Tainted Buffer Access. This code could write past the end of 'data'.
        // Static Code Analysis Tool FP: none
        // Static Code Analysis Tool FP: none
        data[recvResult] = '\0';
    } while (1);
    if (listenSocket != INVALID_SOCKET)
    {
        close(listenSocket);
    }
    if (acceptSocket != INVALID_SOCKET)
    {
        close(acceptSocket);
    }
    return 0;
}