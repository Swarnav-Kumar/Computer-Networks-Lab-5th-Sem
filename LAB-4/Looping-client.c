#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int compare(char a[],char b[])  
{  
    int flag=0,i=0;  // integer variables declaration  
    while(a[i]!='\0' &&b[i]!='\0')  // while loop  
    {  
       if(a[i]!=b[i])  
       {  
           flag=1;  
           break;  
       }  
       i++;  
    }  
    if(flag==0)  
        return 0;  
    else  
        return 1;  
}  
int main()
{
	int cn,bc,c=1,cbyte,size;
	char cstr[200];
	char* end="Bye Server";

	struct sockaddr_in cadd;
	cadd.sin_family = AF_INET;
	cadd.sin_port = (1030);
	cadd.sin_addr.s_addr= INADDR_ANY;

	cn = socket(AF_INET,SOCK_DGRAM,0);

	bc=bind(cn,(struct sockaddr *)&cadd,sizeof(cadd));

	struct sockaddr_in toadd;
	struct sockaddr_in toedit;
	toadd.sin_family = AF_INET;
	toadd.sin_port = (1030);
	toadd.sin_addr.s_addr = INADDR_ANY;

	do
	{
		printf("Enter the message :- \n");
		fgets(cstr,200,stdin);
	
		cbyte=sendto(cn,cstr,strlen(cstr),0,(struct sockaddr*)&toadd,sizeof(toadd));

		if(cbyte == -1)
		{
			printf("Sending message failed!\n");
			return -1;
		}
		printf("Sending message successfull!\n");

        c= compare(cstr,end);

        cbyte=recvfrom(cn,cstr,200,0,(struct sockaddr*)&toadd,&size);

        if(cbyte == -1)
		{
			printf("Message not received at client side!\n");
			return -1;
		}

        printf("Message received at client side!\n");
		printf("\n %d bytes sent\n",cbyte);
		printf("The message sent was %s\n",cstr);		
	}while(c!=0);
		
	return 0;
}
