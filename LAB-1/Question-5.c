/*Write a program to extract each byte as character from the representation
of multibyte data types on your machine and its corresponding memory
locations. By studying the data in memory, findout if the underlying
architecture/machine is little endian or big endian*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    unsigned int num = 0x1A23FEB2;
    unsigned char *ptr = (unsigned char*)&num;

    printf("Location\tByte\n\n");

    for (int i = 0; i < sizeof(num); i++)
    {
        unsigned int a = (unsigned int)ptr;
        printf("%u\t%x\n", a, *(ptr+i));
    }

    if (*ptr == 0xB2)
    {
        printf("\nThe underlying architecture is little endian\n");
    }
    else
    {
        printf("\nThe underlying architecture is big endian\n");
    }

    return 0;
}
