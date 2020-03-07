#include <stdio.h>
int main() {
    char *p1, *p2;
    char s1[16] = "987654321", s2[16] = "G";
    p1 = s1;
    p2 = s2;
    printf("%s\t%s\n", p1, p2);
    printf("%p\t%p\n", p1, p2);
    *p2 = *p1;
    printf("%s\t%s\n", s1, s2); // 值不相等
    printf("%s\t%s\n", p1, p2); // 值不相等
    printf("%p\t%p\n", p1, p2); // 地址不变
    /*    while((*p2++ = *p1++));*/
    /*    printf("%s\t%s\n", s1, s2); // 值不相等*/
    p2 = p1;
    printf("%s\t%s\n", p1, p2); // 值不相等
    printf("%p\t%p\n", p1, p2); // 地址改变
    return 0;
}
