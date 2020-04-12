#include <stdio.h>
#include <stdlib.h>
int gcd(int m, int n) {
    if (n == 0)
        return m;
    return gcd(n, m % n);
}
int lcm(int m, int n) {
    int g = gcd(m, n);
    return g*(m/g)*(n/g);
}
int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s a b to tell the greatest common divisor of a and b "
               "and the lowest common multiple\n ",
               argv[0]);
    } else {
        int a = atoi(argv[1]);
        int b = atoi(argv[2]);
        printf("The greatest common divisor of %s and %s is %d\n", argv[1],
               argv[2], gcd(a, b));
        printf("The lowest common multiple of %s and %s is %d\n", argv[1],
               argv[2], lcm(a, b));
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        printf("The greatest common divisor of %s and %s is %d\n", argv[1],
               argv[2], a);
        printf("The lowest common multiple of %s and %s is %d\n", argv[1],
               argv[2], a * (atoi(argv[1]) / a) * (atoi(argv[2]) / a));
    }
    return 0;
}
