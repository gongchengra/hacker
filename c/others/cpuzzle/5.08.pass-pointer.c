#include <stdio.h>
void swap(int *, int *); // 函数参数采用传地址值的方式
int main() {
    int a = 55, b = 66;
    printf("&a=%p\t &b=%p\n", &a, &b); // 实参地址
    swap(&a, &b);                      // 传地址值
    printf("返回后数据：a=%d, b=%d\n", a, b);
}
void swap(int *p, int *t) {
    int temp;
    printf("&p=%p\t &t=%p\n", &p, &t); // 指针地址
    printf(" p=%p\t t=%p\n", p, t);    // 形参地址
    temp = *p;                         // 交换两个变量的值
    *p = *t;
    *t = temp;
    printf("交换数据为：a=%d, b=%d\n", *p, *t);
}
