#include <stdio.h>
void qq(int);
int main() {
    qq(100);
    return 0;
}
void qq(int n) {
    int i = 0;
    int q[101];
    q[0] = 1;
    for (i = 1; i <= n; ++i)
        q[i] = q[i - 1] + i;
    printf("切100刀最多可分成%d块。\n", q[n]);
}
