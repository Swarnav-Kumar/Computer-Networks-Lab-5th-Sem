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
	
	char ch;
    socklen_t size;


    // receiving operator
	int sbyte = recvfrom(sn, &ch, sizeof(ch), 0, (struct sockaddr*)&fromadd, &size);
	
	if(sbyte==-1)
    {
		printf("Operator not received\n");
		exit(0);
	}
	
	printf("Operator received\n");
	printf("Operator is: %c\n", ch);

	
    // receiving the operands
	int op1, op2;

	sbyte = recvfrom(sn, &op1, sizeof(int), 0, (struct sockaddr*)&fromadd, &size);
	
	if(sbyte==-1)
	{
		printf("First operand not received\n");
		exit(0);
	}
	else
    {
        printf("First operand received\n");
    }
    
    sbyte = recvfrom(sn, &op2, sizeof(int), 0, (struct sockaddr*)&fromadd, &size);
	
	if(sbyte==-1)
	{
		printf("Second operand not received\n");
		exit(0);
	}
	else
    {
        printf("Second operand received\n");
    }
    
    // performing operation
    
    int result;
    switch(ch)
    {
    	case '+': result = op1 + op2;
    		break;
    	
    	case '-': result = op1 - op2;
    		break;
    	
    	case '*': result = op1 * op2;
    		break;
    		
    	case '/': result = op1 / op2;
    		break;
    		
    	case '%': result = op1 % op2;
    		break;
    }
    
    int sarr = sendto(sn, &result, sizeof(result),0,(struct sockaddr *)&fromadd,sizeof(fromadd));
	
	if(sarr==-1)
    {
		printf("Result not sent");
		exit(0);
	}
    else
    	printf("\nResult sent\n");
    
   
	return 0;
}
