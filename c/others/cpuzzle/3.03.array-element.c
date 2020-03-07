#include <stdio.h>
int main() {
    int i = 0, a[3], b[3];
    for (i = 0; i < 3; i++) {
        a[i] = i + 50;
        *(b + i) = i + 50;
    }
    printf("%d %d\n", a[0], *a); // 两种表示方法等效
    for (i = 0; i < 3; i++)
        printf("%d ", a[i]);
    printf("\n");
    for (i = 0; i < 3; i++)
        printf("%d ", *(b + i)); // 与a[i]等效
    printf("\n");
}
