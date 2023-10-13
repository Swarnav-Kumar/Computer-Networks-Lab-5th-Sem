#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>

int compare(char a[],char b[])  
{  
    int flag=0,i=0;    
    while(a[i]!='\0' && b[i]!='\0') 
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
	char sstr[200];
	char* end="Bye Client";
	int sn,bs,sbyte,c=1,size;

	struct sockaddr_in sadd;
	sadd.sin_family = AF_INET;
	sadd.sin_port = (1030);
	sadd.sin_addr.s_addr = INADDR_ANY;

	sn = socket(AF_INET,SOCK_DGRAM,0);
	
	bs=bind(sn,(struct sockaddr *)&sadd,sizeof(sadd));
	
	struct sockaddr_in fradd;
	struct sockaddr_in fredit;
	fradd.sin_family =AF_INET;
	fradd.sin_port = (1030);
	fradd.sin_addr.s_addr = INADDR_ANY;

	do
    {
		sbyte=recvfrom(sn,sstr,200,0,(struct sockaddr*)&fradd,&size);

		if(sbyte == -1)
		{
			printf("Message not received at server side!\n");
			return -1;
		}
		else
		{
			printf("Message received at server side!\n");
			printf("\n %d bytes sent\n",sbyte);
			printf("The message sent was %s\n",sstr);
			
            printf("Enter the message :- \n");
		    fgets(sstr,200,stdin);
	
		    sbyte=sendto(sn,sstr,strlen(sstr),0,(struct sockaddr*)&fradd,sizeof(fradd));
            if(sbyte == -1)
		    {
			    printf("Sending message failed!\n");
			    return -1;
		    }
            printf("Sending message successfull!\n");
        }	
        c = compare(sstr,end);
	}while(c!=0);
	
	return 0;
}
