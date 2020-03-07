#include <stdio.h>
struct LIST {
    int a, b;
} d = {13, 28};
void swap(struct LIST *); // 函数参数采用传地址值的方式
int main() {
    printf("调用前 a=%d,b=%d\n", d.a, d.b);
    swap(&d); // 传结构变量d的地址值
    printf("返回后 a=%d,b=%d\n", d.a, d.b);
}
// 将结构指针作为参数，以传地址值的方式传递这个参数
void swap(struct LIST *s) {
    int temp = s->a;
    s->a = s->b;
    s->b = temp;
    printf("函数中 a=%d,b=%d\n", s->a, s->b);
}
