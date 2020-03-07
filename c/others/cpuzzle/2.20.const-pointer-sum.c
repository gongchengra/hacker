// https://www.geeksforgeeks.org/difference-between-const-int-const-int-const-and-int-const/
/*

int const* is pointer to const int
int *const is const pointer to int
int const* const is const pointer to const int

Using this rule, even complex declarations can be decoded like,

int ** const is a const pointer to pointer to an int.
int * const * is a pointer to const pointer to an int.
int const ** is a pointer to a pointer to a const int.
int * const * const is a const pointer to a const pointer to an int.
*/
#include <stdio.h>
int main() {
    int x = 45, y = 55, *p1; // 变量x和y均能作为左值和右值
    int const sum = 100;     // 常量sum只能作为右值
    int *const p = &x;       // 声明常量指针并使用变量初始化
    int *const p2 = (int *)&sum; // 使用常量初始化常量指针，需要强制转换
    printf("%d %d ", *p, *p2);
    x = y; // 通过左值x间接改变*p的值，使*p=55
    printf("%d ", *p);
    *p = sum; // 直接用*p作为左值，使*p=100
    printf("%d ", *p);
    *p2 = *p2 + sum + *p; // *p2作为左值，使*p2=300
    printf("%d ", *p2);
    p1 = p; // p作为右值，使指针p1与常量指针p的指向相同
    printf("%d\n", *p1);
    return 0;
}
