#include <stdio.h>
/* atoi: convert s to integer */
int atoi(char s[]) {
    int i, n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}
/* lower: convert c to lower case; ASCII only */
int lower(int c) {
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}
int main() {
    char ts[] = "8769123";
    printf("%d\n", atoi(ts));
    /*    printf("%d\n",atoi("8769123"));*/
    printf("%c\n", lower('D'));
}
