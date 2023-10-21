// Program for server to receive an array from client and display it

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
	
	int n;
    socklen_t size;


    // receiving array size
	int sbyte = recvfrom(sn, &n, sizeof(n), 0, (struct sockaddr*)&fromadd, &size);
	
	if(sbyte==-1)
    {
		printf("Array size not received\n");
		exit(0);
	}
	
	printf("Received %d bytes\n", sbyte);
	printf("Array size: %d\n", n);

	
    // receiving the array elements
	float* arr=(float*)malloc(n*sizeof(float));

	sbyte = recvfrom(sn, arr, n*sizeof(float), 0, (struct sockaddr*)&fromadd, &size);
	
	if(sbyte==-1)
	{
		printf("Array not received\n");
		exit(0);
	}
	else
    {
        for(int i=0;i<n-1;i++)
        {
            for (int j=i+1; j<n; j++)
            {
            	if (arr[j]>arr[i])
            	{
            		float temp;
            		temp = arr[i];
            		arr[i]=arr[j];
            		arr[j]=temp;
            	}
            }
        }
    }
    
    int sarr = sendto(sn,arr, n*sizeof(float),0,(struct sockaddr *)&fromadd,sizeof(fromadd));
	
	if(sarr==-1)
    {
		printf("Array not sent");
		exit(0);
	}
    else
    	printf("\nArray sent\n");
    
    
	
    
	return 0;
}
