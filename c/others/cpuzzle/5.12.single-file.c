#include <stdio.h> // 1包含头文件
#define NUM 100    // 2 宏定义NUM=100
int max(int, int); // 3 函数max的原型声明
// 4 空行
int main()       // 5 主函数
{                // 6 主函数定义开始
    int a, b, x; // 7 声明变量
    a = 2;
    b = 3;               // 8 变量赋值
    x = NUM * max(a, b); // 9 输出函数返回值与NUM相乘
    // 10 空行
    printf("%d\n", x); // 11 输出函数返回值与NUM的乘积
    return 0;          // 12
} // 13 主函数结束
// 14 空行
int max(int m1, int m2) // 15 函数max的定义
{                       // 16
    if (m1 > m2)
        return m1 + NUM; // 17 使用m1+NUM
    else
        return m2 + NUM; // 18 使用m2+NUM
} // 19 函数max结束
