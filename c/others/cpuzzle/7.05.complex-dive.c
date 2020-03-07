#include <stdio.h>
#include <stdlib.h>
void dive(double *);
int main() {
    double a[3][2] = {4, 3, 2, 1};
    double b[3][2] = {5, 2, 2, 5};
    double c[3][2] = {5, 2};
    double *p;
    p = a[0];
    dive(p);
    printf("%lf%+lfi\n", p[4], p[5]);
    p = b[0];
    dive(p);
    printf("%lf%+lfi\n", p[4], p[5]);
    p = c[0];
    dive(p);
    printf("%lf%+lfi\n", p[4], p[5]);
    return 0;
}
void dive(double *p) {
    double d;
    if ((p[2] == 0) && (p[3] == 0)) {
        printf("除数为0，退出！\n");
        exit(1);
    }
    d = p[2] * p[2] + p[3] * p[3];
    p[4] = (p[0] * p[2] + p[1] * p[3]) / d;
    p[5] = (p[1] * p[2] - p[0] * p[3]) / d;
}
