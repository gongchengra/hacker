#include <stdio.h>
double s1 = 0.0;
double s2 = 1.0;
double step = 0.01;
double func(), FindValue(double (*)());
int main() {
    double (*p)(); // 定义函数指针
    double x;
    p = func; // 指向目标函数
    x = FindValue(p);
    printf("最小值是：%2.3f\n", x);
    return 0;
}
double func(double x) // 目标函数
{
    return (10 * x * x - 9 * x + 2);
}
/*double FindValue(double (*f)()) // 定义求最小值函数，它包括函数指针*/
/*{*/
/*    double x = s1, y = (*f)(x); // 定义变量y与func函数返回类型一致*/
/*    while (x <= s2) {*/
/*        if (y > (*f)(x))*/
/*            y = (*f)(x);*/
/*        x += step;*/
/*    }*/
/*    return y;*/
/*}*/
double FindValue(double (*f)()) // 定义求最小值函数，它包括函数指针
{
    double x, y = (*f)(); // 定义变量y与func函数返回类型一致
    for (x = s1; x <= s2; x += step)
        if (y > (*f)(x))
            y = (*f)(x);
    return y;
}
