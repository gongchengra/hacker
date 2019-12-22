#include <stdio.h>
#define N 200
long double fibonacci(unsigned int i) {
    static long double f[N];
    if (i <= 1) {
        f[i] = i;
    } else {
        if (f[i] == 0) {
            f[i]= fibonacci(i - 1) + fibonacci(i - 2);
        }
    }
    return f[i];
}

long double fibonacciForLoop(unsigned int i) {
    long double f[N];
    f[0]=0;
    f[1]=1;
    for(int j = 2;j <= i;j++){
        f[j] = f[j-1]+f[j-2];
    }
    return f[i];
}

int main() {
    int i;
    for (i = 0; i < N; i++) {
        printf("%Lf\t\n", fibonacci(i));
        printf("%Lf\t\n", fibonacciForLoop(i));
    }
    return 0;
}
