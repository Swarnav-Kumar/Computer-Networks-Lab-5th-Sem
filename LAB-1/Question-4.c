/* Write a program to extract the first byte and last byte of an unsigned
integer, input with keyboard. If first byte and last byte are same, then it
will ask the user to input a new interger again. This process will continue
till both bytes are same. If both are not same then it will print the message
as “Succeeded with 2 attempts” where 2 is the number of entering the
unsigned number through keyboard.*/

#include <stdio.h>

int main()
{
    int flag=0;
    int  n=0;

    while(!flag)
    {
        unsigned int num;
        printf("Enter the unsigned integer number : \n");
        scanf("%u",&num);
        printf("The number entered in hexadecimal format : %x\n",num);
        unsigned char *c = (unsigned char*) &num;

        unsigned char a,b;

        a=0xFF &  *c;
        c=c+3;
        b=0xFF & *c;

        if(a != b)
        {
            n++;
            flag=1;
            printf("\nSucceeded with %d attempts\n",n);
        }
        else
        {
            n++;
            printf("Attempt failed!,(First and Last byte matching) \n",n);
        }

    }
   
    return 0;
}
