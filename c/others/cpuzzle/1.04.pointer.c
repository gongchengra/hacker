#include <stdio.h>
int main() {
    int a = 65;
    int *p;
    p = &a;
    printf("%p, %p, %p\n", &a, &p, p);
    printf("%d,%d,%d\n", a, *&a, *p);
    return 0;
}
