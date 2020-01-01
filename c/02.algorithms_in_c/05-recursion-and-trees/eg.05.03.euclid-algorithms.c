#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int gcd(int m, int n) {
    if (n == 0)
        return m;
    return gcd(n, m % n);
}
int main(void) {
    srand(time(NULL));
    int i = rand(), j = rand();
    printf("gcd of %d and %d is %d\n", i, j,  gcd(i, j));
    return 0;
}
