#include <stdio.h>
double *add(double *);
int main() {
    double a[3][2] = {4, 3, 2, 1};
    double b[3][2] = {5, 2, 2, 5};
    double c[3][2] = {5, 2};
    double *p = a[0];
    add(p);
    printf("%lf+%lfi\n", p[4], p[5]);
    p = b[0];
    add(p);
    printf("%lf+%lfi\n", p[4], p[5]);
    p = c[0];
    add(p);
    printf("%lf+%lfi\n", p[4], p[5]);
    return 0;
}
double *add(double *p) {
    p[4] = p[0] + p[2];
    p[5] = p[1] + p[3];
    return p;
}
