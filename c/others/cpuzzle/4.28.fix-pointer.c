#include <stdio.h>
int main() {
    int a[3][3], i, *p;
    for (i = 0, p = a[0]; i < 9; p++, i++)
        *p = i + 1;
    for (--p, i = 0; i < 9; i++, --p) {
        if (i % 3 == 0)
            printf("\n");
        printf("%d ", *p);
    }
    printf("\n");
}
