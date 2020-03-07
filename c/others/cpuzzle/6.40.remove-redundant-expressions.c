#include <stdio.h>
struct LIST {
    int a, b;
} d = {3, 8};
void swap(struct LIST *); // 函数参数采用传地址值的方式
int main() {
/*    struct LIST *p = &d; // 多余的方式*/
/*    swap(p);             // 可以直接使用swap(&d)*/
    printf("before: a=%d,b=%d\n", d.a, d.b);
    swap(&d);
    printf("after: a=%d,b=%d\n", d.a, d.b);
}
// 将结构指针作为参数，以传地址值的方式传递这个参数
void swap(struct LIST *s) {
    int temp = s->a;
    s->a = s->b;
    s->b = temp;
    printf("函数中 a=%d,b=%d\n", s->a, s->b);
}
