#include <stdint.h>
#include <stdio.h>
int main() {
    int a = 65;
    intptr_t addr = (intptr_t)&a;
    printf("%p,%p,%p\n", &a, (int *)addr, &addr); // 输出3个地址
    printf("%d,%d,%d\n", a, *&a, *(int *)addr); // 输出变量及地址里的值
    int *p = (int *)addr;
    printf("%d\n", *p);
    return 0;
}
