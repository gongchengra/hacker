#include <stdio.h>
void max(int, int, int *);
int main() {
    int a, b, c;
    printf("输入两个整数：");
    scanf("%d %d", &a, &b);
    max(a, b, &c);
    c = a + b + c;
    printf("c=%d\n", c);
    return 0;
}
void max(int a, int b, int *p) { *p = a < b ? b : a; }
