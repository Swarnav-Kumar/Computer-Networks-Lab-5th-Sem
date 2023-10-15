#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
	int sid, bs, sbyte, size;
	int num;
	
	sid = socket(AF_INET, SOCK_DGRAM, 0);
	
	struct sockaddr_in sadd;
	sadd.sin_family = AF_INET;
	sadd.sin_port = (1030);
	sadd.sin_addr.s_addr = INADDR_ANY;
	
	bs = bind(sid, (struct sockaddr *)&sadd, sizeof(sadd));
	
	struct sockaddr_in fradd;
	fradd.sin_family = AF_INET;
	fradd.sin_port = (1030);
	fradd.sin_addr.s_addr = INADDR_ANY;
	
	sbyte = recvfrom(sid, &num, 8, 0, (struct sockaddr*)&fradd, &size);
	
	if (sbyte == -1)
		printf("Number not received at server side!\n");
	else
	{
		printf("Number received at server side!\n");
		printf("\n%d bytes sent \n", sbyte);
		printf("The number received is: %d\n", num);
	}
	
	if ((num)%2 == 0)
		printf("%d is even!\n", num);
	else
		printf("%d is odd!\n", num);
	
	return 0;
}
