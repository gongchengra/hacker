#include <stdio.h>
/*
int eg_strlen(char *s)
{
    int n;
    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}
*/
int eg_strlen(char *s)
{
    char *p = s;
    while (*p != '\0')
        p++;
    return p - s;
}
int main()
{
    char array[100];
    char *ptr = "Hello";
    int l = eg_strlen("hello, world");
    printf("%d\n", l);
    l = eg_strlen(array);
    printf("%d\n", l);
    l = eg_strlen(ptr);
    printf("%d\n", l);
}
