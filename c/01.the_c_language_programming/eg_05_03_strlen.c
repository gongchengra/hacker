#include <stdio.h>
#include <string.h>
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
    printf("%d\n", eg_strlen("hello, world"));

    char *ptr = "Hello";
    printf("%d\n", eg_strlen(ptr));
    printf("%d\n", (int) strlen(ptr));

    char array[100] = "Test part of array.";
    printf("%d\n", eg_strlen(array));
    printf("%d\n", eg_strlen(&array[5]));
    printf("%d\n", eg_strlen(array+5));
    printf("%s\n", array+5);
}
