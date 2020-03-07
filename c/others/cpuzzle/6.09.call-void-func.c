#include <stdio.h>
void max(int, int); // 函数参数采用传数值方式
int main() {
    int a, b;
    printf("输入两个整数：");
    scanf("%d %d", &a, &b);
    max(a, b);
    return 0;
}
// 将变量作为参数，以传数值方式传递参数
void max(int a, int b) {
    if (a < b)
        printf("最大值是：%d\n", b);
    else
        printf("最大值是：%d\n", a);
}
