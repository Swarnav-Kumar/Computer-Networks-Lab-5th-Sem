#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main()
{
    int sn,bs;
    sn = socket(AF_INET,SOCK_DGRAM,0);

    if (sn == -1) 
    {
        printf("Server socket is not created\n");
        return -1;
    }
    else
        printf("Server socket is created successfully\n");

    struct sockaddr_in sadd;
    sadd.sin_family = AF_INET;
    sadd.sin_port = (1030);
    sadd.sin_addr.s_addr = INADDR_ANY;

    bs = bind(sn,(struct sockaddr *)&sadd,sizeof(sadd));


    if(bs == -1)
    {
        printf("Binding Unsuccessfull!\n");
        exit(0);
    }
    else
        printf("Binding Successfull!\n");
        
    return 0;
}
