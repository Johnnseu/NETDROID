#include <stdio.h>
#include <time.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <errno.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <unistd.h>
#define MAX 65536
int main(int argc , char **argv)
{
      	struct hostent *host;
	int err, i , sock ,start , end;
	char hostname[100];
	struct sockaddr_in sa;
       //Timespec for port scan
        clock_t start_t, end_t;
   double total_t;
   int j;
       start_t = clock();
       end_t = clock();
	printf("[#]scan ");
	scanf("%s %d-%d",  hostname, &start, &end);

	//Initialise the sockaddr_in structure
	strncpy((char*)&sa , "" , sizeof sa);
	sa.sin_family = AF_INET;
	
	//direct ip address, use it
	if(isdigit(hostname[0]))
	{
		printf("Starting port scan INET ADDRESS\n");		sa.sin_addr.s_addr = inet_addr(hostname);
	}
	//Resolve hostname to ip address
	else if( (host = gethostbyname(hostname)) != 0)
	{
		printf("Starting port scan HOSTNAME\n");
		strncpy((char*)&sa.sin_addr , (char*)host->h_addr , sizeof sa.sin_addr);
	}
	else
	{
		herror(hostname);
		exit(2);
	}
	
	//Start the port scan ant timeloop
        printf("Start Time 00:00\n");
	printf("PortScan in progress\n");
        for(j=0; j< 10000000; j++) {
	for( i = start ; i <= end ; i++) 
	{
		//Fill in the port number
                total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		sa.sin_port = htons(i);
		//Create a socket of type internet
		sock = socket(AF_INET , SOCK_STREAM , 0);
		
		//Check whether socket created fine or not
		if(sock < 0) 
		{
			perror("\nSocket");
			exit(1);
		}
		//Connect using that socket and sockaddr structure
		err = connect(sock , (struct sockaddr*)&sa , sizeof sa);
		
		//not connected
		if( err < 0 )
		{
			//printf("%s %-5d %s\r" , hostname , i, strerror(errno));
			fflush(stdout);
		}
		//connected
		else
		{
                  struct servent *service;
                  service = getservbyport(htons(i), NULL);
                 if (service == NULL)
              {
                printf("HOST: %-5s PORT:- %d SERVICE: UNKNOWN PROTO: udp\n", hostname, i);
              }
               else {
       		printf("HOST: %-5s PORT:- %d SERVICE: %s PROTO: tcp\n", hostname, i, service->s_name);
}
	}
		close(sock);
	}
	printf("Time Taken : %f \n", total_t);
	printf("\r");
	fflush(stdout);
	return(0);
}
}
