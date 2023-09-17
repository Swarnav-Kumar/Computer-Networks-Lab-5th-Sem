/* Write a program to extract each byte from a given number and store them
in separate character variables and print the content of those variables.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    unsigned int num = 0x1A23FEB2;
    unsigned char ptr = (unsigned char)&num;

    unsigned char b0 = (num >> 24) & 0xFF;
    unsigned char b1 = (num >> 16) & 0xFF;
    unsigned char b2 = (num >> 8) & 0xFF;
    unsigned char b3 = num & 0xFF;

    printf ("The bytes are: ");
    printf ("%x %x %x %x\n", b0, b1, b2, b3);

    return 0;
}
