#include <stdio.h>
int main() {
    int a = 256, b = 585;
    printf("%p,%p\n", &a, &b);
    printf("%d,%d\n", *&a, *&b);
    printf("%d,%d\n", *(int *)&a, *(int *)&b);
    return 0;
}
