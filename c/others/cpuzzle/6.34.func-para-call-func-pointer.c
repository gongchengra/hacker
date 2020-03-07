#include <stdio.h>
double s1 = 0.0;
double s2 = 1.0;
double step = 0.01;
double func(), value(double (*)());
int main() {
    printf("最小值是：%2.3f\n", value(func)); // 使用函数参数调用
    return 0;
}
// 目标函数
double func(double x) { return (10 * x * x - 9 * x + 2); }
// 定义求最小值函数，使用函数指针作为参数
double value(double (*f)()) {
    double x, y = (*f)(); // 定义变量y与func函数返回类型一致
    for (x = s1; x <= s2; x += step)
        if (y > (*f)(x))
            y = (*f)(x);
    return y;
}
