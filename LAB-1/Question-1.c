/* Write a program to extract the first byte and last byte of an unsigned
integer, input with command line arguments.*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    
    int n=0;
    for(int i = 1; i < argc; i++)
    {
        n = ((n*10) + atoi(argv[i]));
    }
    printf("The number provided through command line : %d\n", n);
    unsigned int num=(unsigned int)n;
    printf("The number entered in hexadecimal format : %X\n",num);
    unsigned char *c = (unsigned char*) &num;

    unsigned char a,b;

    a=0xFF & *c;
    c=c+3;
    b=0xFF & *c;

    printf ("The first byte is : %X\n",a);
    printf ("The last byte is : %X\n",b);
    
    return 0;
}
