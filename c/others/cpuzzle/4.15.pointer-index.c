#include <stdio.h>
int main() {
    int a[] = {1, 2, 3, 4, 5}, *p, i;
    p = a;
    for (i = 4; i > -1; --i)
        printf("%d ", p[i]); // 第一条输出语句
    printf("\n");
    p = &a[2];
    printf("%d %d\n", p[0], p[1]); // 第二条输出语句
    p = &a[4];
    printf("%d %d\n", p[0], p[-1]); // 第三条输出语句
    for (i = 0; i > -5; --i)
        printf("%d ", p[i]); // 第四条输出语句
    printf("\n");
}
