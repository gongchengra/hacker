#include <stdio.h>
int main() {
    int a = 55, b = 66, *p = &a;
    printf("&a:%p, &b:%p, &p:%p\n", &a, &b, &p);
    printf("%d %d &a:%p &p:%p\n", a, b, p, &p);
    a = 88;
    *p = a;
    printf("%d %d &a:%p &p:%p\n", a, *p, p, &p);
    p = &b;
    printf("%d %d &b:%p &p:%p\n", a, *p, p, &p);
    return 0;
}
