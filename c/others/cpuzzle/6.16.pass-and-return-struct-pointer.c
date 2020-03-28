#include <stdio.h>
/*struct LIST {*/
/*    int a, b;*/
/*} d = {3, 8};*/
// or
typedef struct LIST {
    int a, b;
} lst;
lst d = {3, 8};
lst e;
struct LIST *swap(struct LIST *); // 函数参数采用传地址值的方式
int main() {
    printf("调用前 a=%d,b=%d\n", d.a, d.b);
    swap(&d); // 传结构变量d的地址值
    printf("返回后 a=%d,b=%d\n", d.a, d.b);
    e.a = 2 * d.a;
    e.b = 3 * d.b;
    printf("返回后 a=%d,b=%d\n", e.a, e.b);
}
// 将结构指针作为参数，以传地址值的方式传递这个参数
struct LIST *swap(struct LIST *s) {
    int temp = s->a;
    s->a = s->b;
    s->b = temp;
    printf("函数中 a=%d,b=%d\n", s->a, s->b);
    return s;
}
