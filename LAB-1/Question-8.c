/* Write a program to modify the above program to regenerate the original
number from the structure members. Display the number.*/
#include <stdio.h>

struct pkt
{
    char ch1;
    char ch2[2];
    char ch3;
};

int main()
{
    // Create an instance of the struct
    struct pkt myPacket;

    // Initialize the structure members
    myPacket.ch1 = 'A';
    myPacket.ch2[0] = 'B';
    myPacket.ch2[1] = 'C';
    myPacket.ch3 = 'D';

    // Regenerate the original number from the structure members
    unsigned int regeneratedValue = 0;
    regeneratedValue |= ((unsigned int)myPacket.ch1 & 0xFF);
    regeneratedValue |= ((unsigned int)myPacket.ch2[0] << 8) & 0xFF00;
    regeneratedValue |= ((unsigned int)myPacket.ch2[1] << 16) & 0xFF0000;
    regeneratedValue |= ((unsigned int)myPacket.ch3 << 24) & 0xFF000000;

    // Display the regenerated number
    printf("Regenerated Number: %X\n", regeneratedValue);

    return 0;
}
