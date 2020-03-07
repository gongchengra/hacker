#include <stdio.h>
#include <stdlib.h>
int main() {
    char *p, *q;
    p = q = (char *)malloc(100);
    scanf("%s", q);
    while (*p != '\0')
        p++;
    printf("%ld\n", p - q);
    free(q);
}
