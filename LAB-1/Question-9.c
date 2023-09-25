/* Write a program to extract each byte from an signed integer and display
the content of each location in decimal.*/

#include <stdio.h>

int main() 
{
    int num;
    printf("Enter a signed integer: ");
    scanf("%d", &num);

    unsigned char byte1 = (num >> 24) & 0xFF;
    unsigned char byte2 = (num >> 16) & 0xFF;
    unsigned char byte3 = (num >> 8) & 0xFF;
    unsigned char byte4 = num & 0xFF;

    printf("Hexadecimal representation of each byte:\n");
    printf("Byte 1: %X\n", byte1);
    printf("Byte 2: %X\n", byte2);
    printf("Byte 3: %X\n", byte3);
    printf("Byte 4: %X\n", byte4);

    printf("Decimal representation of each byte:\n");
    printf("Byte 1: %d\n", byte1);
    printf("Byte 2: %d\n", byte2);
    printf("Byte 3: %d\n", byte3);
    printf("Byte 4: %d\n", byte4);

    return 0;
}
