#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
	int cn, cs, cbyte, size, num;
	
	cn = socket(AF_INET, SOCK_DGRAM, 0);
	
	struct sockaddr_in cadd;
	cadd.sin_family = AF_INET;
	cadd.sin_port = (1040);
	cadd.sin_addr.s_addr = INADDR_ANY;
	
	cs = bind(cn, (struct sockaddr *)&cadd, sizeof(cadd));
	
	struct sockaddr_in toadd;
	toadd.sin_family = AF_INET;
	toadd.sin_port = (1030);
	toadd.sin_addr.s_addr = INADDR_ANY;
	
	printf("Enter the number: \n");
	scanf("%d", &num);
	
	cbyte = sendto(cn, &num, sizeof(num), 0, (struct sockaddr*)&toadd, sizeof(toadd));
	
	if (cbyte == -1)
	{
		printf("Sending number failed!\n");
		return -1;
	}
	else
		printf("Sending number successful!\n");
	
	return 0;
}
