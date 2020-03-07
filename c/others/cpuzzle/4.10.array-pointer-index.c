#include <stdio.h>
#define size 2
int main() {
    int i, a[size], b[size], *p;
    for (i = 0; i < size; i++)
        scanf("%d%d", a + i, &b[i]);
    p = b;
    for (i = 0; i < size; i++)
        printf("%d %d %d %d ", *(a + i), b[i], *(p + i), p[i]);
    printf("\n");
    p = a;
    for (i = 0; i < size; i++)
        scanf("%d", p + i);
    for (i = 0; i < size; i++)
        printf("%d ", i[a]);
    printf("%d", 1[a]); // equals a[1] *(a+1)
    printf("\n");
}
