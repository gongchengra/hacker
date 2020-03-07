#include <stdio.h>
int x = 4, y = 5; // 外部对象
int main()        // 主程序开始
{                 // 第1程序块开始
    {
        int x = 1; // 第2程序块开始
        {
            int x = 2; // 第3程序块开始
            {
                int x = 3;                      // 第4程序块开始
                printf("x=%d,&x=%p\n", x, &x); // 输出第4块的x和存储地址
                printf("y=%d,&y=%p\n", y, &y); // 输出外部的y和存储地址
            }                                   // 第4程序块结束
            printf("x=%d,&x=%p\n", x, &x); // 输出第3块的x和存储地址
            printf("y=%d,&y=%p\n", y, &y); // 输出外部的y和存储地址
        }                                   // 第3程序块结束
        printf("x=%d,&x=%p\n", x, &x);     // 输出第2块的x和存储地址
        printf("y=%d,&y=%p\n", y, &y);     // 输出外部的y和存储地址
    }                                       // 第2程序块结束
    printf("x=%d,&x=%p\n", x, &x);         // 输出外部的x和存储地址
    printf("y=%d,&y=%p\n", y, &y);         // 输出外部的y和存储地址
} // 主程序结束
