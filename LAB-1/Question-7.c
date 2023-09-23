/* Write a program to extract each byte as character from the representation
of multibyte data types on your machine and store the above extracted
bytes with the following structure. Now display the contains of structure
members. struct pkt
{
char ch1;
char ch2[2];
char ch3;
}*/

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
    struct pkt mP;

    // Initialize a multibyte value (you can change this to any value you want)
    unsigned m = 0x12345678;

    // Extract individual bytes and store them in the struct
    mP.ch1 = (char)(m & 0xFF);
    mP.ch2[0] = (char)((m >> 8) & 0xFF);
    mP.ch2[1] = (char)((m >> 16) & 0xFF);
    mP.ch3 = (char)((m >> 24) & 0xFF);

    // Display the contents of the structure members
    printf("ch1: %x\n", mP.ch1);
    printf("ch2[0]: %x\n", mP.ch2[0]);
    printf("ch2[1]: %x\n", mP.ch2[1]);
    printf("ch3: %x\n", mP.ch3);

    return 0;
}
