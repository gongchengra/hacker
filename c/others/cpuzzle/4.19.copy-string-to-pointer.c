#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int i = 0, j = 0;
    char t[] = "abcdefghij", s[] = "klmnopqrstuvwxyz", *p;
    // wrong because unsafe
    /*    p = t;*/
    /*    i = strlen(t);*/
    /*    while ((p[i + j] = s[j]) != '\0')*/
    /*        j++;*/
    if ((p = (char *)malloc(strlen(t) + strlen(s) + 1)) == NULL) {
        printf("内存分配错误!\n");
        exit(1);
    }
    while ((p[i] = t[i]) != '\0')
        i++;
    while ((p[i + j] = s[j]) != '\0')
        j++;
    p[i + j] = '\0';
    printf("%s\n", p);
    printf("%lu\n", strlen(p));
    // elegant way
    for (i = strlen(p) - 1; i > -1; i--)
        printf("%c", p[i]);
    printf("\n");
    // ugly way
    /*    p = p + 25;*/
    /*    for (i = 0; i > -26; i--)*/
    /*        printf("%c", p[i]);*/
    /*    printf("\n");*/
    /*    p = p - 25;*/
    free(p);
    return 0;
}
