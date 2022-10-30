#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>

int main(int argc, char *argv[]){
    struct hostent *host_info;
    struct in_addr *address;

    char input[1024];

    printf("HOSTNAME: ");
   scanf("%s", input);
    printf("starting DNS query on hostname %s\n", input);

    host_info = gethostbyname(input);
    address = (struct in_addr *) (host_info->h_addr);
    printf("HOSTNAME:%s has ADDRESS:%s\n", input, inet_ntoa(*address));
}
