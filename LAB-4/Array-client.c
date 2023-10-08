#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
	
	int cn=socket(AF_INET,SOCK_DGRAM,0);
	
	struct sockaddr_in cadd;
	cadd.sin_family=AF_INET;
	cadd.sin_port=3000;
	cadd.sin_addr.s_addr=INADDR_ANY;
	
	int bc=bind(cn,(struct sockaddr *)&cadd,sizeof(cadd));
	
	struct sockaddr_in toadd;
	toadd.sin_family=AF_INET;
	toadd.sin_port=5000;
	toadd.sin_addr.s_addr=INADDR_ANY;
	
	int n;
	printf("\nEnter the number of elements in array: ");
	scanf("%d",&n);
	
	int csize=sendto(cn,&n, sizeof(n),0,(struct sockaddr *)&toadd,sizeof(toadd));
	
	if(csize==-1){
		printf("Size not sent");
		exit(0);
	} 
	printf("\nSize sent\n");
	
	int* arr=(int *)malloc(n*sizeof(int));
	printf("Enter the elements: \n");
	for(int i=0;i<n;i++){
		printf("%d element:",i+1);
		scanf("%d",&arr[i]);
	}
	
	for(int i=0;i<n;i++){
		printf("%d ",*(arr+i));
	}
	
	int carr=sendto(cn,arr, n*sizeof(int),0,(struct sockaddr *)&toadd,sizeof(toadd));
	
	if(carr==-1){
		printf("Array not sent");
		exit(0);
	} 
	printf("\nArray sent\n");
	
	return 0;
}
