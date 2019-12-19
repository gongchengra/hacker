#include <stdio.h>
#include <ctype.h>
/* atoi: convert s to integer; version 2 */
int atoi(char s[])
{
    int i, n, sign;
    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    return sign * n;
    /* skip white space */
    /* skip sign */
}
int main()
{
    char ts[] = "8769123";
    printf("%d\n",atoi(ts));
/*    printf("%d\n",atoi("8769123"));*/
}
