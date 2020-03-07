#include <stdio.h>
int main() {
    int a[3][3];
    a[0][0] = 128;
    printf("%p %p %p %p %d\n", a, &a[0][0], &a[0], a[0], *a[0]);
}
