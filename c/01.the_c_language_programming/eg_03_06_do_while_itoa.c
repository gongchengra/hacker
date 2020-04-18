#include <stdio.h>
#include <string.h>
/* reverse: reverse string s in place */
void reverse(char s[]) {
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
/* itoa: convert n to characters in s */
void itoa(int n, char s[]) {
    int i = 0, sign;
    if ((sign = n) < 0)        /* record sign */
        n = -n;                /* make n positive */
    do {                       /* generate digits in reverse order */
        s[i++] = n % 10 + '0'; /* get next digit */
    } while ((n /= 10) > 0);   /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
int main() {
    char ts[100];
    int i = -987654321;
    itoa(i, ts);
    printf("%s\n", ts);
    /*    printf("%d\n",atoi("8769123"));*/
}
