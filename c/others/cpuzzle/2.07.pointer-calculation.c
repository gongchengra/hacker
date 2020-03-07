#include <stdio.h>
int main() {
    int x = 56, y = 65, *p = &x; // 指针指向x
    printf("%p,%p,%p,%p\n", &x, &y, p, &p);
    printf("%d,%p,%p,%d\n", x, p, &p, *p);
    p = &y; // 指针改为指向存放y的首地址
    printf("%d,%p,%p,%d\n", y, p, &p, *p);
    *p = 66; // 通过指针改变变量内容
    printf("%d,%p,%p,%d\n", y, p, &p, *p);
    --p; // 对指针进行减1运算，使其指向指针变量的首地址
    printf("%d,%p,%p,%d\n", x, p, &p, *p);
    ++p; // 对指针进行增1运算，使其指向存放y的首地址
    printf("%d,%p,%p,%d\n", x, p, &p, *p);
    ++p; // 对指针进行增1运算，使其指向存放x的首地址
    printf("%d,%p,%p,%d\n", x, p, &p, *p);
    ++p; // 对指针进行增1运算，使其指向程序之外的地址
    printf("%d,%p,%p,%d\n", x, p, &p, *p);
    --p; // 对指针进行减1运算，使其指向存放x的首地址
    printf("%d,%p,%p,%d\n", x, p, &p, *(p - 1));
    *p = *(p - 1); // 通过指针将变量y的值赋给x
    printf("%d,%p,%p,%d\n", x, p, &p, *p);
}
