#include <stdio.h>
#include <stdlib.h>
void dive(double[][2]);
int main() {
    double a[3][2] = {4, 3, 2, 1};
    double b[3][2] = {5, 2, 2, 5};
    double c[3][2] = {5, 2};
    dive(a);
    printf("%lf%+lfi\n", a[2][0], a[2][1]);
    dive(b);
    printf("%lf%+lfi\n", b[2][0], b[2][1]);
    dive(c);
    printf("%lf%+lfi\n", c[2][0], c[2][1]);
    return 0;
}
void dive(double a[][2]) {
    double d;
    if ((a[1][0] == 0) && (a[1][1] == 0)) {
        printf("除数为0，退出！\n");
        exit(1);
    }
    d = a[1][0] * a[1][0] + a[1][1] * a[1][1];
    a[2][0] = (a[0][0] * a[1][0] + a[0][1] * a[1][1]) / d;
    a[2][1] = (a[0][1] * a[1][0] - a[0][0] * a[1][1]) / d;
}
