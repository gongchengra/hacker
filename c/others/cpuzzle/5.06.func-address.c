#include <stdio.h>
double max(double, double);
int main() {
    double a = 5.8, b = 8.5;
    printf("&a=%p, &b=%p\n", &a, &b);
    printf("max=%f\n", max(a, b));
}
double max(double m, double n) {
    printf("&m=%p, &n=%p\n", &m, &n);
    if (m > n)
        return m;
    else
        return n;
}
