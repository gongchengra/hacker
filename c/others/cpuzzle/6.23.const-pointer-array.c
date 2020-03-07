#include <stdio.h>
int strlen1(const char *);
int strlen2(const char[]);
int main() {
    char array[46] = "How are you? Fine,and you? See you tomorrow!";
    char *p = "Goodbye!";
    char *pt = &array[35];
    printf("%d\t", strlen1(array));
    printf("%d\t", strlen1("hello, word"));
    printf("%d\n", strlen1(p));
    printf("%d\t", strlen2(array));
    printf("%d\t", strlen2("hello, word"));
    printf("%d\n", strlen2(p));
    printf("%d\t%d\n", strlen1(pt), strlen2(pt));
    printf("%d\t%s\n", strlen1(&array[35]), &array[35]);
    printf("%d\t%s\n", strlen2(&array[35]), &array[35]);
}
int strlen1(const char *s) {
    int n;
    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}
int strlen2(const char s[]) {
    int n;
    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}
