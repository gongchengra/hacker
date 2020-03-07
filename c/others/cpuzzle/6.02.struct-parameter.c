#include <stdio.h>
struct LIST {
    int a, b;
} d[3];
struct LIST make(int, int);  // 返回结构的函数
void disp(struct LIST[]);    // 使用结构参数
void display(struct LIST *); // 使用结构指针参数
int main() {
    d[0] = make(25, 52);
    d[1] = make(85, 58);
    d[2] = make(68, 86);
    disp(d); // 这里的d以结构数组作为参数
    display(d); // 这里的d以结构的首地址出现，即结构指针作为参数
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
        printf("d[%d].a=%d,d[%d].b=%d\n", i, d[i].a, i, d[i].b);
}
void display(struct LIST *p) {
    int i;
    for (i = 0; i < 3; i++)
        printf("d[%d].a=%d,d[%d].b=%d\n", i, (p + i)->a, i, (p + i)->b);
}
