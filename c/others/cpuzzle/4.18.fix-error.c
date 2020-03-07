#include <stdio.h>
int main() {
    char s[] = "Good Afternoon!";
    // wrong char t[20], p = t;
    char t[20], *p = t;
    int m = 6, n = 10;
    {
        int i;
        for (i = 0; i < n; i++)
            p[i] = s[m - 1 + i];
        p[i] = '\0';
    }
    printf("%s", p);
    printf("\n%s\n", t);
}
