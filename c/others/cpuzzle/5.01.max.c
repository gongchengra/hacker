#include <stdio.h>          // 1
double max(double, double); // 2 函数max的原型声明
int main()                  // 3 主函数
{                           // 4 主函数定义开始
    double a, b, x;         // 5 声明变量
    a = 2.5;                // 6 变量赋值
    b = 3.5;                // 7 变量赋值
    x = max(a, b);          // 8 函数调用
    printf("%f\n", x);      // 9 输出函数返回值
    return 0;               // 10 返回0值
} // 11 结束
// 12 空行
/*
double max(double m, double n) // 13 函数max的定义
{                              // 14
    if (m > n)                 // 15
        return m;              // 16
    else                       // 17
        return n;              // 18
} // 19
*/
double max(double m, double n) { return m > n ? m : n; }
