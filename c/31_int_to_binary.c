#include <stdio.h>
// https://stackoverflow.com/questions/5488377/converting-an-integer-to-binary-in-c
unsigned int_to_int(unsigned k) {
    if (k == 0)
        return 0;
    if (k == 1)
        return 1; /* optional */
    return (k % 2) + 10 * int_to_int(k / 2);
}
// Convert an integer to binary integer : the integer to convert binary : the
// string containing the conversion result n : number of bits (8, 16, 32 ...)
void int2bin(unsigned integer, char *binary, int n) {
    for (int i = 0; i < n; i++)
        binary[i] = (integer & (int)1 << (n - i - 1)) ? '1' : '0';
    binary[n] = '\0';
}
int main(int argc, char *argv[]) {
    int i;
    char s[33];
    printf("Input the integer you want to convert:\n");
    scanf("%d", &i);
    int2bin(i, s, 32);
    printf("(%d)10 = (%s)2\n", i, s);
    // printf("%d", int_to_int(i));
}
