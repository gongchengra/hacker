#include <stdio.h>
int main() {
    int a = 36, b = 63, c = 656, i = 0;
    int *p = &b;
    printf("%d %d %d\n", p[1], p[0], p[-1]);
    for (i = 1; i > -2; i--)
        printf("%d ", p[i]);
    printf("\n");
    return 0;
}
