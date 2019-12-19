#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}
const char *byte_to_binary(int x)
{
    static char b[9];
    b[0] = '\0';

    int z;
    for (z = 128; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}
void bin(unsigned n)
{
    /* step 1 */
    if (n > 1)
        bin(n/2);

    /* step 2 */
    printf("%d", n % 2);
}
/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
    int b;
    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;
    return b;
}
int main()
{
    int n = 255*255;
    printf("%d\n",getbits(255,4,3));
    printf("%s\n",byte_to_binary(259));
    printf("%s\n",byte_to_binary(255&077));
    printf("%s\n",byte_to_binary(1&2));
    printf("%s\n",byte_to_binary(255*255));
    bin(n);
    bin(-1);
    printf("\n");
    printf("The color: %s\n", "blue");
    printf("First number: %d\n", 12345);
    printf("Second number: %04d\n", 25);
    printf("Third number: %i\n", 1234);
    printf("Float number: %3.2f\n", 3.14159);
    printf("Hexadecimal: %x\n", 65025);
    printf("Octal: %o\n", n);
    printf("Unsigned value: %u\n", 255);
    printf("Octal: %o\n", 255);
    printf("There are %d 1 in %o\n", bitcount(255),255);
    printf("Unsigned value: %u\n", 255>>2);
    printf("Octal: %o\n", 255>>2);
    printf("Unsigned value: %u\n", 255<<2);
    printf("Octal: %o\n", 255<<2);
}
