#include <stdio.h>
int main() {
    int a[] = {1, 2, 3, 4, 5}, *p, i;
    char c[] = "abcde", *cp;
    p = &a[2];
    cp = &c[2];
    for (i = 0; i < 3; ++i)
        printf("%d%c%d%c", *(p + i), *(cp + i), *(p - i), *(cp - i));
    // wrong printf("\n%d%s%c\n", *p, *cp, cp);
    printf("\n%d%c%s\n", *p, *cp, cp);
    *cp = 'W';
    cp = c;
    *cp = 'A';
    printf("%c%s\n", *cp, cp);
    printf("%s", c);
}
