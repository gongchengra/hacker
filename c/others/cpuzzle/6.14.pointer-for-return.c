#include <stdio.h>
#include <stdlib.h>
int *sp(int[]);
int main() {
    int a[3] = {1, 3, 5}, i, *p;
    for (i = 0; i < 3; i++)
        printf("%d ", a[i]);
    printf("\n");
    p = sp(a);
    for (i = 0; i < 3; i++)
        printf("%d ", *(p + i));
    printf("\n");
    return 0;
}
int *sp(int *s) {
    int *p;
    p = (int *)(malloc(sizeof(s)));
    p[0] = 2 + s[0];
    p[1] = 4 + s[1];
    p[2] = 6 - s[2] + p[1];
    free(p);
    return p;
}
