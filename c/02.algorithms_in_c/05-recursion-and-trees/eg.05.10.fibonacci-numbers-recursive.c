#include <stdio.h>
#define N 30
int F(int i) { return (i < 2) ? i : F(i - 1) + F(i - 2); }
int main(void) {
    printf("%d\n", F(N));
    return 0;
}
