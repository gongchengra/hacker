#include <stdio.h>
#include <stdlib.h>
int main() {
    char *s;
    int n;
    s = (char *)malloc(50);
    scanf("%s", s);
    for (n = 0; *s != '\0'; ++s)
        ++n;
    s = s - n;
    free(s);
    printf("%d", n);
}
