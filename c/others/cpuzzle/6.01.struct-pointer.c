#include <stdio.h>
#include <stdlib.h>
struct LIST {
    int a, b;
} d[3], *p;
// 返回结构值
struct LIST make1(int x, int y) {
    struct LIST temp;
    temp.a = x;
    temp.b = y;
    return temp;
}
// 返回结构指针
struct LIST *make2(int x, int y) {
    struct LIST *temp;
    temp = (struct LIST *)malloc(sizeof(struct LIST));
    temp->a = x;
    temp->b = y;
    return temp;
}
int main() {
    int i;
    d[0] = make1(25, 52);
    p = make2(85, 58);
    d[1] = *p;
    d[2] = d[0]; // 结构可以整体赋值
    for (i = 0; i < 3; i++)
        printf("d[%d].a=%d,d[%d].b=%d\n", i, d[i].a, i, d[i].b);
    return 0;
}
