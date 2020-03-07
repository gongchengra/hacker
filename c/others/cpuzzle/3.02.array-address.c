#include <stdio.h>
int main() {
    int i = 0, a[3] = {2, 4, 6};
    printf("%p %p %p\n", a, &a, &a[0]); // 3种表示方法等效
    printf("%p\n", &i);                 // 变量i的首地址
    for (i = 0; i < 3; i++)             // 与a + i表示方法等效
        printf("%p ", &a[i]);
    printf("\n");
    for (i = 0; i < 3; i++) // 与&a[i]表示方法等效
        printf("%p ", a + i);
    printf("\n");
    for (i = 0; i < 3; i++) // &a[i]+i 表示的含义不同
        printf("%p ", &a + i);
    printf("\n");
}
