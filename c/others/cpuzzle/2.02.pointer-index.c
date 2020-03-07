#include <stdio.h>
int main() {
    int a = 36, b = 63, c = 656, i = 0, *p = &a;
    for (i = 0; i > -3; i--)
        printf("%4d", p[i]);
    printf("\n");
    p = &c;
    for (i = 0; i < 3; i++)
        printf("%4d", p[i]);
    printf("\n");
    return 0;
}
