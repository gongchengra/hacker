#include <stdio.h>       // 预编译命令
#include <string.h>      // 字符串库函数
void find(char (*)[12]); // 注意声明参数的格式
int main() {
    char str[2][12] = {"不是罪犯", "是罪犯"}; // 初始化字符数组
    find(str);                                // 注意调用参数的表示
    return 0;
}
void find(char (*str)[12]) // 注意定义参数的声明方式
{
    int tj1, tj2, tj3, tj4, tj5, tj6;
    int A, B, C, D, E, F;
    // 使用6重循环
    for (A = 0; A <= 1; A++)
        for (B = 0; B <= 1; B++)
            for (C = 0; C <= 1; C++)
                for (D = 0; D <= 1; D++)
                    for (E = 0; E <= 1; E++)
                        for (F = 0; F <= 1; F++) {
                            tj1 = A || B;
                            tj2 = !(A && D);
                            tj3 = (A && E) || (A && F) || (E && F);
                            tj4 = (B && C) || (!B && !C);
                            tj5 = (C && !D) || (D && !C);
                            tj6 = D || (!E);
                            // 判断是否符合条件，符合则打印结果
                            if (tj1 + tj2 + tj3 + tj4 + tj5 + tj6 == 6) {
                                printf("A:%s\n", str[A]);
                                printf("B:%s\n", str[B]);
                                printf("C:%s\n", str[C]);
                                printf("D:%s\n", str[D]);
                                printf("E:%s\n", str[E]);
                                printf("F:%s\n", str[F]);
                            }
                        }
}
