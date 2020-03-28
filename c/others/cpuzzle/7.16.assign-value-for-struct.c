#include <stdio.h>
struct List {
    char c;
    int num;
    char name[12];
    float fnum[2];
} a;
void disp() {
    printf("输入一个字符:");
    scanf("%c", &a.c);
    printf("输入一个整数:");
    scanf("%d", &a.num);
    printf("输入一个字符串:");
    scanf("%s", a.name); // &a.name等效
    {
        int i = 0;
        printf("输入两个浮点数:");
        for (i = 0; i < 2; i++)
/*            scanf("%f", (a.fnum + i)); // a.fnum错误,等效&a.fnum[i]*/
            scanf("%f", &a.fnum[i]); // a.fnum错误,等效&a.fnum[i]
    }
    printf("%c,%d,%s,%f,%f\n", a.c, a.num, a.name, a.fnum[0], a.fnum[1]);
    printf("%c,%d,%s,%f,%f\n", a.c, a.num, &a.name[4], *(a.fnum),
           *(a.fnum + 1));
}
int main() { disp(); }
