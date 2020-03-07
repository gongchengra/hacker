#include <stdio.h>
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
    int i;
    for (i = 0; i <= 63; i++) {
        A = (i & 32) >> 5;
        B = (i & 16) >> 4;
        C = (i & 8) >> 3;
        D = (i & 4) >> 2;
        E = (i & 2) >> 1;
        F = i & 1;
        tj1 = A || B;
        tj2 = !(A && D);
        tj3 = (A && E) || (A && F) || (E && F);
        tj4 = (B && C) || (!B && !C);
        tj5 = (C && !D) || (D && !C);
        tj6 = D || (!E);
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
