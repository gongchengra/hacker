#include <stdio.h>
int main() {
    int a[3][3], i, *p;
    p = a[0];
    for (i = 0; i < 9; i++)
        *(p + i) = i + 1;
    for (i = 0; i < 9; i++) {
        if (i % 3 == 0 && i != 0)
            printf("\n");
        printf("%d ", p[i]);
    }
    printf("\n");
    return 0;
}
