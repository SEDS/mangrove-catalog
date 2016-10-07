// Juliet CWE666_Operation_on_Resource_in_Wrong_Phase_of_Lifetime__listen_bind_accept_18.c
// Program to send data to a socket. Used in conjunction with the buffer-store-socket program.

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
    char data[SIZE] = "This is a test";

    int sendSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);


    struct sockaddr_in addrLocal;
    addrLocal.sin_family = AF_INET;
    addrLocal.sin_port = htons(9999);
    // addrLocal.sin_addr = INADDR_ANY; // zero-init sin_addr to tell it to use all available adapters on the local host

    // associate this socket with local UDP port 9999
    int bindStatus = bind(sendSocket, (struct sockaddr*)&addrLocal, 0);
    printf("Socket bound on local port.\n");

    struct sockaddr_in addrDest;
    addrDest.sin_family = AF_INET;
    addrDest.sin_port = htons(TCP_PORT);
    // inet_pton(AF_INET, "10.234.135.41", &addrDest.sin_addr); // Static Code Analysis Tool server
    inet_pton(AF_INET, "52.91.252.238", &addrDest.sin_addr); // AWS server



    // socklen_t sockSize;
    // sockSize = sizeof(struct sockaddr_in);

    printf("Sending data.\n");
    ssize_t sentSize = sendto(sendSocket, data, strlen(data) + 1, MSG_NOSIGNAL, (struct sockaddr*)&addrDest, sizeof(addrDest));
    printf("Data sent. Size sent: %zd\n", sentSize);

    return 0;
}

