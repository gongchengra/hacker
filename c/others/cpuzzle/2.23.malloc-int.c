#include <stdio.h>
#include <stdlib.h>
int main() {
    int i, *p;
    p = (int *)malloc(8);
    for (i = 0; i < 2; ++i, ++p)
        scanf("%d", p);
    p = p - 2;
    for (i = 0; i < 2; ++i, ++p)
        printf("%d ", *p);
    printf("\n");
    p = p - 2;
    free(p);
}
