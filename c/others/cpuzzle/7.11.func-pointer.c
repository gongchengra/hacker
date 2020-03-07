#include <stdio.h>
void all(int, int, int (*)());
int max(int, int), min(int, int), mean(int, int);
int main() {
    int a, b;
    printf("输入a和b的值：");
    scanf("%d %d", &a, &b);
    printf("max=");
    all(a, b, max);
    printf("min=");
    all(a, b, min);
    printf("mean=");
    all(a, b, mean);
}
void all(int x, int y, int (*func)(int x, int y)) {
    printf("%d\n", (*func)(x, y));
}
int max(int x, int y) { return x > y ? x : y; }
int min(int x, int y) { return x < y ? x : y; }
int mean(int x, int y) { return ((x + y) / 2); }
