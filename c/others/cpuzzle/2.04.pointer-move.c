#include <stdio.h>
int main() {
    long a = 88, b = 58, c = 98, i = 0;
    long *p;
    p = &a;
    printf("%p, %p, %p, %p, %p\n", &a, &b, &c, &i, &p);
    for (i = 0; i < 4; i++, p--)
        printf("%ld ", *p);
    printf("\n");
    printf("%p \n", p);
    a = (long)p;
    printf("%ld\n", *(long *)a);
    a = 66;
    for (p++, i = 0; i < 4; i++, p++)
        printf("%ld ", *p);
    printf("\n");
    printf("%ld ", *p);
    printf("%p ", p);
    c = (long)&b;
    printf("%ld\n", *(long *)c);
    return 0;
}
