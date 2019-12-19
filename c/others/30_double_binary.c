// http://www.ruanyifeng.com/blog/2010/06/ieee_floating-point_representation.html
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
    u1.f = 20.0;
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
