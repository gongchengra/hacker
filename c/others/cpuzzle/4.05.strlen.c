#include <stdio.h>
#include <stdlib.h>
int main() {
    char *p, *s;
    p = s = (char *)malloc(128);
    scanf("%s", s);
    while (*p++);
    printf("%ld\n", (p - s));
}
