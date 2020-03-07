#include <stdio.h>
int main() {
    char c = 'B', *p = &c;
    printf("%p, %p, %p\n", &c, &p, p);
    printf("%c, %c, %c\n", c, *&c, *p);
    return 0;
}
