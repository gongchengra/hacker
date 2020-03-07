#include <stdio.h>
struct List {
    char *name;
    int num;
} a;
void disp() {
    char c[12];
    printf("输入姓名：");
    scanf("%s", c); // 注意字符串中不能有空格
    a.name = c;
    printf("输入编号：");
    scanf("%d", &a.num);
    printf("%s,%d\n", a.name, a.num);
}
int main() { disp(); }
