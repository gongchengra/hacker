#include <stdio.h>
int main() {
    int a[] = {1, 2, 3, 4, 5}, *p, i;
    printf("%p,%p,%p,%p,%p\n", a, &a[0], &a, p, &p);
    p = a;
    printf("%p,%p,%p,%p,%p\n", a, &a[0], &a, p, &p);
    printf("%p,%p,%p\n", p, &p[0], &p);
    for (i = 0; i < 5; ++i)
        printf("%d ", p[i]);
    printf("\n");
    return 0;
}
