#include <stdio.h>
void change(const int[]); // 数组原型形式
int main() {
    int i, a[] = {10, 20, 30, 40, 50};
    change(a);
    for (i = 0; i < 5; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
// 只使用传递参数的值
void change(const int a[]) {
    int x = a[0] + a[3];
    printf("x=%d\n", x);
}
