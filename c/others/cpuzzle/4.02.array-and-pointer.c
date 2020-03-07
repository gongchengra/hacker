#include <stdio.h>
#define sa(a) sizeof(a)/sizeof(a[0])
int main() {
    int a[] = {1, 3, 5, 7, 9}, *p = a, i; // 相当于int *p=&a[0];
    for (i = 0; i < sa(a); ++i)               // 演示3种输出方式
        printf("%d %d %d ", a[i], *(a + i), *(p + i));
    printf("\n%p,%p\n", a, p); // 演示a即数组首地址
    for (i = 0; i < sa(a); i++)      // 演示指针使用下标
        printf("%d ", p[i]);
    for (; p < a + sa(a); ++p) // 演示从a[0]开始输出至a[4]
        printf("%d ", *p);
    for (--p; p >= a; --p) // 演示从a[4]开始输出至a[0]
        printf("%d ", *p);
    printf("\n");
}
