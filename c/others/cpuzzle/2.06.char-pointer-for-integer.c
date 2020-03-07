#include <stdio.h>
int main() {
    int a = 0x12345678, i = 0;
    char *p;
    p = (char *)&a;
    printf("%p, %s\n", &a, p);
    for (i = 0; i < 4; i++, p++)
        printf("%p, %x\n", p, *p);
    return 0;
}
