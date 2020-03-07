#include <stdio.h>
void add(double[][2]);
int main() {
    double a[3][2] = {4, 3, 2, 1};
    double b[3][2] = {5, 2, 2, 5};
    double c[3][2] = {5, 2};
    double(*p)[2]; // 可直接用double (*p)[2]=a;
    p = a;
    add(p);
    printf("%lf+%lfi\n", a[2][0], a[2][1]);
    add(b);
    printf("%lf+%lfi\n", b[2][0], b[2][1]);
    add(c);
    printf("%lf+%lfi\n", c[2][0], c[2][1]);
    return 0;
}
void add(double a[][2]) {
    a[2][0] = a[0][0] + a[1][0];
    a[2][1] = a[0][1] + a[1][1];
}
