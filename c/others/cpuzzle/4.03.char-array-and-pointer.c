#include <stdio.h>
int main() {
    int i = 0;
    char a[] = "ABCD", *p = "abcd"; // 定义字符串和字符串常量
    printf("%s,%s\n", a, p);        // 整体输出各自的内容
    for (i = 0; i < 4; i++)         // 演示指针使用下标输出a b c d
        printf("%c ", p[i]);
    while (*p)              // 顺序输出字符串常量，直到为空
        printf("%c", *p++); // 依次输出当前*p, 即输出abcd
    p = p - 2;              // p指向字符常量中的字符c
    printf(" %s\n", p);     // 输出字符cd
    p = a; // 指针p改为指向a，即p不再指向字符串常量
    printf("%s,%s\n", a, p); // 整体输出，两者内容一样，均为ABCD
}
