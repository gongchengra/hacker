#include <stdio.h>
int main() {
    int a[] = {1, 2, 3, 4, 5}, *p, i;
    p = a;
    for (i = 4; i > -1; --i)
        printf("%d ", p[i]);
    printf("\n");
    // wrong p = &a[4];
    p = &a[0];
    for (i = 4; i > -1; --i)
        printf("%d ", p[i]);
    printf("\n");
    // or
    p = &a[4];
    for (i = 0; i < 5; i++)
        printf("%d ", p[-i]);
    printf("\n");
}
