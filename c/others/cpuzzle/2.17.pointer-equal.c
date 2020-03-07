#include <stdio.h>
int main() {
    int *p1, *p2;
    int s1 = 0x12345678, s2 = 0x78;
    p1 = &s1;
    p2 = &s2;
    printf("%p\t%p\n", p1, p2);
    *p2 = *p1;
    printf("%x\t%x\n", *p2, *p1); // 值相等
    printf("%p\t%p\n", p1, p2);   // 地址不变
    p2 = p1;
    printf("%x\t%x\n", *p1, *p2); // 值相等
    printf("%p\t%p\n", p1, p2);   // 地址改变
    return 0;
}
