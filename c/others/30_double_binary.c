// http://www.ruanyifeng.com/blog/2010/06/ieee_floating-point_representation.html
// f = (-1)^s * M * 2^E
// s = (f > 0) ? 0 : 1;
// 1 <= M < 2
// for 32 bit float, first bit is s, following 8 bits are E, last 23 bits are M.
// for example, 20.0=(10100)2=1.01 * 2^4
// for M, since M >=1, the first bit is always 1 therefore can be ignored.
// 1.01 becomes .01
// for E, the range is 0-255, therefore we need to add 127 in case of minus value.
// 4 becomes 131 (10000011)2
// so 20.0 is 0 10000011 0100000000000000000000000
// for 64 bit double, first bit is s, following 11 bits are E, last 53 bits are M.
// for E, the range is 0-2047, therefore we need to add 1023 in case of minus value.
// so 20.0 is 0 10000000011 0100000000000000000000000000000000000000000000000000000
#include <stdio.h>
#include <stdlib.h>
char *decimal_to_binary(int n)
{
    int c, d, count;
    char *pointer;
    count = 0;
    pointer = (char*)malloc(32+1);
    if (pointer == NULL)
        exit(EXIT_FAILURE);
    for (c = 31 ; c >= 0 ; c--)
    {
        d = n >> c;
        if (d & 1)
            *(pointer+count) = 1 + '0';
        else
            *(pointer+count) = 0 + '0';
        count++;
    }
    *(pointer+count) = '\0';
    return  pointer;
}
int main(){
    union ufloat {
        float f;
        unsigned u;
    };
    union ufloat u1;
    u1.f = 0.0;
    printf("%d\n", u1.u);

    union udouble {
        double d;
        unsigned long long u;
    };
    union udouble u2;
    u2.d = 1.0;
    printf("%lld\n", u2.u);

    unsigned long n;
    char *p;
    printf("Enter an integer in decimal number system\n");
    scanf("%ld",&n);
    p = decimal_to_binary(n);
    printf("Binary string of %ld is: %s\n", n, p);
    free(p);
    return 0;
}
