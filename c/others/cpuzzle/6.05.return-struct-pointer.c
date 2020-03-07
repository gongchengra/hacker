#include <stdio.h>
#include <stdlib.h>
struct LIST {
    int a, b;
} d[3], b, *p;
struct LIST make(int, int);                        // 返回结构的函数
struct LIST *change(struct LIST *, struct LIST[]); // 返回结构的指针
void disp(struct LIST[]);                          // 使用结构参数
int main() {
    d[0] = make(25, 52);
    d[1] = make(85, 58);
    d[2] = make(68, 86);
    p = &b;           // 初始化指针p
    p = change(p, d); // 表达式调用
    disp(d);
    printf("b.a=%d\t\tb.b=%d\n", b.a, b.b);
    printf("p->a=%d\t\tp->b=%d\n", p->a, p->b);
    return 0;
}
struct LIST make(int x, int y) {
    struct LIST *temp;
    temp = (struct LIST *)malloc(sizeof(*temp));
    temp->a = x;
    temp->b = y;
    return *temp;
}
void disp(struct LIST d[]) {
    int i;
    for (i = 0; i < 3; i++)
        printf("d[%d].a=%d\td[%d].b=%d\n", i, d[i].a, i, d[i].b);
}
// 将传递的一个结构参数作为函数的返回值
struct LIST *change(struct LIST *b, struct LIST d[]) {
    b->a = d[0].a;
    b->b = d[2].b;
    return b;
}
