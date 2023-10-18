// Program to send number to server

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
	

    // sending the operator
	char ch;
	printf("\nEnter the operator: ");
	scanf("%c",&ch);
	
	int csize=sendto(cn,&ch, sizeof(ch),0,(struct sockaddr *)&toadd,sizeof(toadd));
	
	if(csize==-1){
		printf("Operator not sent");
		exit(0);
	} 
	printf("\nOperator sent!\n");
	

    // sending the operands
    int op1, op2;
	printf("Enter the first operand: \n");
	scanf("%d", &op1);
	
	int carr = sendto(cn, &op1, sizeof(op1),0,(struct sockaddr *)&toadd,sizeof(toadd));
	
	if(carr==-1)
    {
		printf("First operand not sent");
		exit(0);
	}
    else
    	printf("\nFirst operand sent\n");
    	
    printf("Enter the second operand: \n");
	scanf("%d", &op2);
	
	carr = sendto(cn, &op2, sizeof(op2),0,(struct sockaddr *)&toadd,sizeof(toadd));
	
	if(carr==-1)
    {
		printf("Second operand not sent");
		exit(0);
	}
    else
    	printf("\nSecond operand sent\n");
    
    int size;
    int result;
    int cbyte = recvfrom(cn, &result, sizeof(int), 0, (struct sockaddr*)&toadd, &size);
	
	if(cbyte==-1)
	{
		printf("Result not received\n");
		exit(0);
	}
	else
	{
		printf("Result received!\n\n");
		printf("The result is: %d\n", result);
	}
	printf("\n");
	
	return 0;
}
