#include <stdio.h>
int fac(int);
int main() {
    int i;
    for (i = 1; i <= 4; i++)
        printf("%d !=%d\n", i, fac(i));
    return 0;
}
int fac(int n) {
    int f = 1;
    int i = 1;
    for (i = 1; i <= n; i++)
        f = f * i;
    return (f);
}
