/* Write a program to find out if the underlying architecture/machine is little
endian or big endian.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    unsigned int num = 0x1A23FEB2;
    unsigned char *ptr = (unsigned char *)&num;

    printf("The LSB of number entered by the user is B2\n");
    printf("The MSB of number entered by the user is 1A\n");
    printf("The number stored in LSB location is extracted to be: %0x\n", *ptr);

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
