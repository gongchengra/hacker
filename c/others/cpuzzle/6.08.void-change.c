#include <stdio.h>
struct LIST {
    int a, b;
} d[3], b[3], *p;
struct LIST make(int, int);                // 返回结构的函数
void change(struct LIST *, struct LIST[]); // 简化为void类型
void disp(struct LIST[]);                  // 使用结构参数
int main() {
    d[0] = make(25, 52);
    d[1] = make(85, 58);
    d[2] = make(68, 86);
    p = b;
    change(p, d);
    disp(d);
    disp(b);
    return 0;
}
struct LIST make(int x, int y) {
    struct LIST temp;
    temp.a = x;
    temp.b = y;
    return temp;
}
void disp(struct LIST d[]) {
    int i;
    for (i = 0; i < 3; i++)
        printf("d[%d].a=%d\td[%d].b=%d\n", i, d[i].a, i, d[i].b);
}
// 简化为void类型，演示传递一个结构参数的指针
void change(struct LIST *b, struct LIST d[]) {
    int i = 0;
    for (i = 0; i < 3; i++) {
        (b + i)->a = d[i].a + i;
        (b + i)->b = d[i].b + i;
    }
}
