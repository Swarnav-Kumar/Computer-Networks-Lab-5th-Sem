#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main()
{
    int sn,bs,sbyte,size;
    char sstr[200];

    sn = socket(AF_INET,SOCK_DGRAM,0);

    struct sockaddr_in sadd;
    sadd.sin_family = AF_INET;
    sadd.sin_port = (1030);
    sadd.sin_addr.s_addr = INADDR_ANY;

    bs = bind(sn,(struct sockaddr *)&sadd,sizeof(sadd));

    struct sockaddr_in fradd;
    fradd.sin_family = AF_INET;
    fradd.sin_port = (1030);
    fradd.sin_addr.s_addr = INADDR_ANY;
    sbyte=recvfrom(sn,sstr,200,0,(struct sockaddr*)&fradd,&size);
    if(sbyte==-1)
    {
        printf("Message not received at the server side\n");
    }
    else
    {
        printf("Message received at the server side\n");
        printf("\n %d bytes sent\n",sbyte);
        printf("The message received is :- %s",sstr);
    }

    printf("Enter the message :- \n");
    fgets(sstr,200,stdin);
    sbyte=sendto(sn,sstr,strlen(sstr),0,(struct sockaddr*)&fradd,sizeof(fradd));

    if(sbyte==-1)
    {
        printf("Sending message failed!\n");
        return -1;
    }
    else
    {
        printf("Sending message succesfull!\n");
    }

    return 0;
}
