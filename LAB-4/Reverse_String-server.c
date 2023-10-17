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
        printf("String not received at the server side!\n");
    }
    else
    {
        printf("String received at the server side\n");
        printf("\n%d bytes sent\n",sbyte);
        printf("The string received is : %s",sstr);
        
        int n = strlen(sstr);

        for (int i = 0, j = n-2; i<=j; i++, j--)
        {
            char temp;
            temp = sstr[i];
            sstr[i] = sstr[j];
            sstr[j] = temp;
        }

        printf("\n");
        printf("The string after reversal is: %s",sstr);
    }

    return 0;
}
