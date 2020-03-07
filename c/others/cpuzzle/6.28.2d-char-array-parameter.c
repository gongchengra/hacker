#include <stdio.h>
#include <string.h>
void display(char (*str)[20]);
int main() {
    char str[3][20];
    int i;
    for (i = 0; i < 3; i++) {
        printf("输入字符串%d:", i + 1);
        gets(str[i]);
    }
    display(str); // 等效语句display(&str[0])
    return 0;
}
void display(char (*str)[20]) {
    int i;
    for (i = 0; i < 3; i++)
        printf("字符串%d:%s\n", i + 1, str[i]);
}
