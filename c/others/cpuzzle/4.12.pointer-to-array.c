#include <stdio.h>
int main() {
    int a[] = {1, 2, 3, 4, 5}, *p, i;
    // warning    p = &a;
    p = a; // or p = &a[0];
    for (i = 0; i < 5; ++i)
        printf("%d ", p[i]); // 输出1 2 3 4 5
    for (i = 4; i > -1; --i)
        printf("%d ", p[i]); // 输出 5 4 3 2 1
    printf("\n");
    return 0;
}
