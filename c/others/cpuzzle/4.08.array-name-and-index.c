#include <stdio.h>
#define size 2
int main() {
    int i, a[size], b[size];
    int *p;
    for (i = 0; i < size; i++)
        scanf("%d%d", a + i, &b[i]); // 两种赋值方法
    p = a;
    for (i = 0; i < size; i++)
        printf("%d %d %d ", *(a + i), b[i],
               i[b]); // 三种输出方法，i[b]是非标准用法
    printf("\n");
}
