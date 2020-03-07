#include <stdio.h>
#include <stdlib.h>
struct List {
    char *name;
    int num;
} a;
void disp() {
    char *p = (char *)malloc(12 * sizeof(char));
    printf("输入姓名：");
    scanf("%s", p);
    a.name = p;
    printf("输入编号：");
    scanf("%d", &a.num);
    printf("%s,%d\n", a.name, a.num);
}
int main() { disp(); }
