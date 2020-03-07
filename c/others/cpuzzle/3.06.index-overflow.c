#include <stdio.h>
int main() {
    int i, a[5];
    for (i = 1; i <= 5; i++)
        a[i] = i;
    printf("%d", a[4]);
    return 0;
}
