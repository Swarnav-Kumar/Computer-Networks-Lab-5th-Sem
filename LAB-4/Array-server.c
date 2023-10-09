#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() 
{
	int sn = socket(AF_INET, SOCK_DGRAM, 0);	
	
	struct sockaddr_in sadd;
	sadd.sin_family = AF_INET;
	sadd.sin_port = 5000;
	sadd.sin_addr.s_addr = INADDR_ANY;
	
	int bs = bind(sn, (struct sockaddr*)&sadd, sizeof(sadd));
	
	struct sockaddr_in fromadd;
	struct sockaddr_in* p = &fromadd;
	fromadd.sin_family=AF_INET;
	fromadd.sin_port=3000;
	fromadd.sin_addr.s_addr=INADDR_ANY;
	
	int n,size;

	int sbyte = recvfrom(sn, &n, 4, 0, (struct sockaddr*)&fromadd, &size);
	
	if(sbyte==-1){
		printf("Not received\n");
		exit(0);
	}
	
	printf("Received %d bytes\n", sbyte);
	printf("n: %d\n", n);
	
	struct sockaddr_in response;
	response.sin_family=AF_INET;
	response.sin_port=3000;
	response.sin_addr.s_addr=INADDR_ANY;
	
	int* arr=(int*)malloc(n*sizeof(int));

	sbyte = recvfrom(sn, arr, n*sizeof(int), 0, (struct sockaddr*)&fromadd, &size);
	
	if(sbyte==-1){
		printf("Array Not Received\n");
		exit(0);
	}
	int sum = 0;
	printf("Array Received %d bytes\n", sbyte);
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
		sum += arr[i];
	}
    printf("\n");
	printf("The sum of the elements of the array is : %d\n",sum);
	return 0;
}
