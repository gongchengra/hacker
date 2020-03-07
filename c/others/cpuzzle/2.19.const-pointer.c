#include <stdio.h>
int main() {
    int x = 55;       // 变量x能作为左值和右值
    const int y = 88; // 常量y不能作为左值，但可以作为右值
    const int *p;     // 声明指向常量的指针
    int *p1;          // 声明指针
    p = &y; // 用常量初始化指向常量的指针，*p不能作为左值
    printf("%d ", *p);
    p = &x; // p作为左值，使常量指针改为指向变量x,*p不能作为左值
    printf("%d ", *p);
    x = 128; // 用x作为左值间接改变*p的值,使*p=x=128
    printf("%d ", *p);
    p1 = (int *)&y; // 非常量指针指向常量需要强制转换
    printf("%d\n", *p1);
    return 0;
}
