#include <stdio.h>
#include <string.h>
int main() {
    char s[] = "abcd"; // 定义字符串
    int i = 0;
    printf("%s\n", s);      // 整体输出内容
    for (i = 0; i < strlen(s); i++) // 顺序输出
        printf("%c ", s[i]);
    printf("\n");
}
