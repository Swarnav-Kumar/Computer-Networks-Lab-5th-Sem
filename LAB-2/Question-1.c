#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main()
{
    int cn,cs;
    cn = socket(AF_INET,SOCK_DGRAM,0);

    if (cn == -1) 
    {
        printf("Client socket is not created\n");
        return -1;
    }
    else
        printf("Client socket is created successfully\n");

    struct sockaddr_in cadd;
    cadd.sin_family = AF_INET;
    cadd.sin_port = (1035);
    cadd.sin_addr.s_addr = INADDR_ANY;

    cs = bind(cn,(struct sockaddr *)&cadd,sizeof(cadd));


    if(cs == -1)
    {
        printf("Binding Unsuccessfull!\n");
        exit(0);
    }
    else
        printf("Binding Successfull!\n");
        
    return 0;
}
