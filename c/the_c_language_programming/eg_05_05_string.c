#include <stdio.h>
/* strlen: return length of string s */
int strlen1(char *s)
{
    char *p = s;
    while (*p != '\0')
        p++;
    return p - s;
}
/* strcpy: copy t to s; array subscript version */
void strcpy1(char *s, char *t)
{
    int i;
    i = 0;
    while ((s[i] = t[i]) != '\0')
        i++;
}
/* strcpy: copy t to s; pointer version */
void strcpy2(char *s, char *t)
{
    int i;
    i = 0;
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}
/* strcpy: copy t to s; pointer version 2 */
void strcpy3(char *s, char *t)
{
    while ((*s++ = *t++) != '\0') ;
}
/* strcpy: copy t to s; pointer version 3 */
void strcpy4(char *s, char *t)
{
    while ((*s++ = *t++));
}
/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmp1(char *s, char *t)
{
    int i;
    for (i = 0; s[i] == t[i]; i++)
        if (s[i] == '\0')
            return 0;
    return s[i] - t[i];
}
/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmp2(char *s, char *t)
{
    for ( ; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}
int main(void)
{
    char s[100];
    char *t = "Test strcpy;";

    strcpy1(s,t);
    printf("%s\n", t);

    strcpy2(s,t);
    printf("%s\n", t);

    strcpy3(s,t);
    printf("%s\n", t);

    strcpy4(s,t);
    printf("%s\n", t);

    strcpy1(s+strlen1(s),t);
    printf("%s\n", s);
    printf("%d\n", strcmp1(s,t));
    printf("%d\n", strcmp2(s,t));

    return 0;
}
