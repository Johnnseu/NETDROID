#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("\n%s [IP]\n", argv[0]);
        printf("For e.g. %s 10.32.129.77\n", argv[0]);
        exit(-1);
    }

    struct sockaddr_in sa;
    int res = inet_pton(AF_INET, argv[1], &sa.sin_addr);
    switch (res) {
    case 0:
        printf("\nInput address is not a valid IPv4 address.\n");
    case -1:
        if (res == -1)
            printf("\nError(%s)\n", strerror(errno));

        int n_res = inet_pton(AF_INET6, argv[1], &sa.sin_addr);
        switch (n_res) {
        case 0:
            printf("\nInput address is not a valid IPv6 address.\n");
        case -1:
            if (n_res == -1)
                printf("\nError(%s)\n", strerror(errno));
            exit(-1);
        case 1:
            sa.sin_family = AF_INET6;
        }
    case 1:
        sa.sin_family = AF_INET;
    }
    printf("This is not 100 percent acurrate\n");
    printf("if online and hostname is IP, try the second time\n");
    char node[NI_MAXHOST];
    memset(node, 0, NI_MAXHOST);
    res = getnameinfo((struct sockaddr *)&sa, sizeof sa, node, sizeof node, NULL, 0, 0);
    if (res) {
        printf("%s\n", gai_strerror(res));
        exit(1);
    }
    printf("Ip addr         |  Hostname\n");
    printf("%s     %s\n", argv[1], node);

    return 0;
}
