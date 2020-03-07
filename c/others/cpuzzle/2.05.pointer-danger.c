#include <stdio.h>
int main() {
    long a = 55, b = 58, c = 98, i = 0;
    long *p;
/*    p = (long *)&i;*/
    p = (long *)&p;
    printf("%p, %p, %p, %p, %p\n", &a, &b, &c, &i, p);
    printf("%ld, %ld, %ld, %ld, %ld\n", a, b, c, i, *p);
    p = (long *)&c;
    printf("%p, %p, %p, %p, %p\n", &a, &b, &c, &i, p);
    printf("%ld, %ld, %ld, %ld, %ld\n", a, b, c, i, *p);
    *p = 12345;
    printf("%ld, %ld, %ld, %ld, %ld\n", a, b, c, i, *p);
    return 0;
}
