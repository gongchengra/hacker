#include <stdio.h>              // 预编译命令
int step = 1;                   // 整型全局变量,预置1,步数
void move(int, char, char, char); // 声明要用到的被调用函数
int main()
{
    int n;                   // 整型变量,n为盘数,
    printf("请输入盘数 n="); // 提示信息
    scanf("%d", &n);         // 输入正整数n
    printf("在3根柱子上移%d只盘的步骤为:\n", n);
    move(n, 'a', 'b', 'c'); // 调用函数 move(n,'a','b','c')
}
void move(int m, char p, char q, char r)
{ // 自定义函数体开始
    if (m == 1) // 如果m为1,则为直接可解结点,
    {
        // 直接可解结点,输出移盘信息
        printf("[%d] move 1# from %c to %c\n", step, p, r);
        step++; // 步数加1
    } else      // 如果不为1,则要调用move(m-1)
    {
        move(m - 1, p, r, q); // 递归调用move(m-1)
        // 直接可解结点,输出移盘信息
        printf("[%d] move %d# from %c to %c\n", step, m, p, r);
        step++;               // 步数加1
        move(m - 1, q, p, r); // 递归调用move(m-1)
    }
} // 自定义函数体结束
