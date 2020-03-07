#include "5.22.b.h"
int r1 = 5;       // 定义外部变量
int r2 = 7;       // 定义外部变量
void test(int r1) // 定义test函数
{
    printf("test函数内:\t&r1=%p\t&r2=%p\n", &r1, &r2);
    printf("test函数内:\t%d*%d=%d\n", r1, r2, r1 * r2);
}
