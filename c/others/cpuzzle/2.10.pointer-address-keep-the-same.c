#include <stdio.h>
int main() {
    int a = 15, b = 38, c = 35, i = 0;
    int *p = &a;                                   // 5
    printf("%p,%p,%p\n", &a, &b, &c);        // 6
    printf("%p,%p,%p,%d\n", &p, *&p, p, *p); // 7
    for (i = 0; i < 3; i++, p--)                   // 8
        printf("%d ", *p);                         // 9
    printf("\n%d,%p,%p\n", *p, p, &p);         // 10
    for (i = 0, ++p; i < 3; i++, p++)              // 11
        printf("%d ", *p);                         // 12
    printf("\n%d,%p,%p\n", *p, p, &p);         // 13
    --p;                                           // 14
    for (i = 0; i < 3; i++)                        // 15
        printf("%d ", *(p - i));                   // 16
    printf("\n%d,%p,%p\n", *p, p, &p);         // 17
    for (i = 0; i < 3; i++)                        // 18
        printf("%d ", *(p - 2 + i));               // 19
    printf("\n%d,%p,%p\n", *p, p, &p);         // 20
    return 0;
}
