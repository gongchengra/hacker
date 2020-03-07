#include <stdio.h>
int main() {
    int a[] = {1, 2, 3, 4, 5}, *p, i;
    p = &a[2];
    for (i = 0; i < 3; ++i) {
        printf("%d %d", *(p + i), *(p - i));
        printf("\n");
    }
    return 0;
}
