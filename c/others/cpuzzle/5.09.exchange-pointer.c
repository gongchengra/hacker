#include <stdio.h>
void swap(int *, int *); // 函数参数采用传地址值的方式
int main() {
    int a = 55, b = 66;
    printf("原来地址为：&a=%p\t &b=%p\n", &a, &b);
    swap(&a, &b); // 传地址值
    printf("返回后地址：&a=%p\t &b=%p\n", &a, &b);
    printf("返回后数据： a=%d\t b=%d\n", a, b);
}
void swap(int *p, int *t) {
    int *temp;
    printf("传递地址为： p=%p\t t=%p\n", p, t);
    printf("传递数据为：*p=%d\t *t=%d\n", *p, *t);
    temp = p; // 交换两个指针的指向
    p = t;
    t = temp;
    printf("交换地址为： p=%p\t t=%p\n", p, t);
    printf("交换数据为：*p=%d\t *t=%d\n", *p, *t);
    // *p=99;
}
