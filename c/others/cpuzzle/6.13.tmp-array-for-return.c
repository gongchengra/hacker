#include <stdio.h>
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
int b[3];
int *sp(int s[]) {
    // wrong int b[3];
    b[0] = 2 + s[0];
    b[1] = 4 + s[1];
    b[2] = 6 - s[2] + b[1];
    return b;
}
