#include <stdio.h>
int main() {
    int a = 5, b = 6, c = 0, d = 0, e = 0;
    c = a-- - b;
    printf("a=%d b=%d c=%d\n", a, b, c);
    a = 5;
    d = a-- - b;
    printf("a=%d b=%d d=%d\n", a, b, d);
    a = 5;
    e = a - --b;
    printf("a=%d, b=%d e=%d\n", a, b, e);
    return 0;
}
