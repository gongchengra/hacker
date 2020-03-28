#include <stdio.h>
void add(double, double, double *);
int main() {
    double a = 5.5, b = 15.39, c = 0;
    add(a, b, &c);
    c = 10 * c;
    printf("c=%f\n", c); // 输出c=208.965000
}
void add(double m, double n, double *q) {
    *q = m + n + 0.0065;
}
