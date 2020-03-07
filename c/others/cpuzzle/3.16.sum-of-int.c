#include <stdio.h>
int main() {
    int i, sum;
    static int a[] = {-15, 8, -225, -24, 56, -158};
    sum = 0;
    for (i = 0; i < 6; i++) {
        if (a[i] < 0)
            continue;
        sum = sum + a[i];
    }
    printf("sum=%d\n", sum);
}
