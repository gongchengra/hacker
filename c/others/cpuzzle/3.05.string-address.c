#include <stdio.h>
int main() {
    char s[] = "fish";
    printf("%p %p\n", &s, s);
    printf("%10u %u\n", &s, s);
    printf("%10d %d\n", &s, s);
    printf("%10s %s\n", &s, s);
    return 0;
}
