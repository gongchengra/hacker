#include <stdio.h>
double add(double, double);
int main() {
    double a = 5.5, b = 15.39, c;
    c = add(a, b);
    c = 10 * c;
    printf("c=%f\n", c);
}
double add(double m, double n) {
    /*    double x = m + n + 0.0065;*/
    /*    return x;*/
    return m + n + 0.0065;
}
