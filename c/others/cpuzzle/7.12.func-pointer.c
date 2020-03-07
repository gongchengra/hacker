#include <stdio.h>
double s1 = 0.0;
double s2 = 1.0;
double step = 0.01;
double func(), MinValue(double (*)());
int main() {
    double (*p)(); // 定义函数指针
    p = func;      // 指向目标函数
    printf("最小值是：%2.3f\n", MinValue(p));
    printf("最小值是：%2.3f\n", MinValue(func));
    return 0;
}
double func(double x) // 目标函数
{
    return (10 * x * x - 9 * x + 2);
}
double MinValue(double (*f)()) // 定义求最小值函数，它包括函数指针
{
    double x = s1, y = (*f)(x); // 定义变量y与func函数返回类型一致
    while (x <= s2) {
        if (y > (*f)(x))
            y = (*f)(x);
        x += step;
    }
    return y;
}
