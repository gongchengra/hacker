#include <stdio.h>
long factorial(int x) { return x < 1 ? 1 : x * factorial(x - 1); }
int main() {
    int n;
    printf("输入整数 n=");
    scanf("%d", &n);
    printf("%d!=%ld\n", n, factorial(n));
}
