/* Write a C program to convert Littel Endian to Big Endian format by using
a suitable user defined function for it.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void littletobig(unsigned char *ptr, unsigned int num)
{
    for (int i = 0; i < (sizeof(num))/2; i++)
    {
        unsigned char temp = ptr[i];
        ptr[i] = ptr[sizeof(num) - i - 1];
        ptr[sizeof(num) - i - 1] = temp;
    }

    printf ("The number after conversion from little endian to big endian is: 0x%x%x%x%x\n", *ptr, *(ptr+1), *(ptr+2), *(ptr+3));
}


int main()
{
    unsigned int num = 0x1A23FEB2;
    unsigned char *ptr = (unsigned char*)&num;

    printf ("The number in little endian format is: 0x%x%x%x%x\n", *ptr, *(ptr+1), *(ptr+2), *(ptr+3));

    littletobig(ptr, num);

    return 0;
}
