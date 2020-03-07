#include <stdio.h>
int main() {
    char a = 'B';
    long addr = (long)&a;
    printf("%p, %ld, %p\n", &a, addr, (char *)addr);
    printf("%c, %c, %c\n", a, *&a, *(char *)addr);
    return 0;
}
