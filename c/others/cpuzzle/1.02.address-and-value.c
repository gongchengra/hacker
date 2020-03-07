#include <stdio.h>
int main() {
    int a = 65;
    long addr = (long)&a;
    printf("%p, %ld, %p\n", &a, addr, (int *)addr);
    printf("%d,%d,%d\n", a, *&a, *(int *)addr);
    return 0;
}
