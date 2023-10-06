#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main()
{
    int cn,cs,cbyte,size;
    char cstr[200];

    cn = socket(AF_INET,SOCK_DGRAM,0);
    
    struct sockaddr_in cadd;
    cadd.sin_family = AF_INET;
    cadd.sin_port = (1030);
    cadd.sin_addr.s_addr = INADDR_ANY;

    cs = bind(cn,(struct sockaddr *)&cadd,sizeof(cadd));
    
    struct sockaddr_in toadd;
    toadd.sin_family=AF_INET;
    toadd.sin_port = (1030);
    toadd.sin_addr.s_addr=INADDR_ANY;

    printf("Enter the message :- \n");
    fgets(cstr,200,stdin);
    cbyte=sendto(cn,cstr,strlen(cstr),0,(struct sockaddr*)&toadd,sizeof(toadd));

    if(cbyte==-1)
    {
        printf("Sending message failed!\n");
        return -1;
    }
    else
    {
        printf("Sending message succesfull!\n");
    }

    cbyte=recvfrom(cn,cstr,200,0,(struct sockaddr*)&toadd,&size);
    if(cbyte==-1)
    {
        printf("Message not received at the client side\n");
    }
    else
    {
        printf("Message received at the client side\n");
        printf("\n %d bytes sent\n",cbyte);
        printf("The message received is :- %s",cstr);
    }

        
    return 0;
}
