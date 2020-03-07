#include <stdio.h>
double max(double m, double n) { return m > n ? m : n; }
int main() {
    double a = 5.5, b = 15.39, c = 15.25;
    printf("max=%f\n", max(c, max(a, b))); // 输出15.390000
}
