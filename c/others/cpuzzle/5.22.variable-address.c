#include <stdio.h>
#include <stdlib.h>
int a;
static int b;
char ch; // 没有初始化
int c = 10;
char s1[] = "OKwe";
char c1 = 'w';            // 初始化
const int i = 25;         // 全局常量
char *p = "We are here!"; // 全局常量
int r1 = 5;                   // 外部变量赋值
int r2 = 7;                   // 外部变量赋值
void test(int r1)         // 函数test
{
    printf("test函数内:\t&r1=%p\t&r2=%p\n", &r1, &r2);
    printf("test函数内:\t%d*%d=%d\n", r1, r2, r1 * r2);
}
int main() {
    int num = 0;
    const int n = 25;
    volatile int result = 15;
    static int m = 15;
    int *p1, *p2;
    char *pc = "She is here!";
    char st[] = "We are here!";
    extern int r1, r2;       // 声明外部变量
    p2 = (int *)malloc(100); // 分配堆
    p1 = &num;
    printf("全局没初始化:\t%p %p %p\n", &a, &b, &ch);
    printf("全局初始化:\t%p %p %p\n", &c, &c1, &s1);
    printf("全局常量:\t%p %p\n", &i, &p);
    printf("局部常量:\t%p %p %p %p\n", &n, pc, p2, &m);
    printf("局部变量:\t%p %p %p %p %p %p\n", &num, &result, p1, &pc, &p1, &p2);
    printf("两种常量:\t%p %p %p %p\n", p, &p, pc, &pc);
    printf("局部字串:\t%p %p %p %p\n", st, &st, pc, &pc);
    printf("函数地址:\t%p %p\n", &main, &test);
    printf("主函数内:\t&r1=%p\t&r2=%p\n", &r1, &r2);
    test(r1);
    return 0;
}
