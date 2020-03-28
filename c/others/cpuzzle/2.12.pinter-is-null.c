#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char *p;
    if ((p = (char *)malloc(100)) == NULL) {
        printf("内存不够！\n");
        exit(1);
    }
    // warning: this program uses gets(), which is unsafe.
    // gets(p);
    /*    const int bufsize = 100; |+ Or a #define or whatever +|*/
    /*    fgets(p, bufsize, stdin);*/
    fgets(p, 100, stdin);
    /*    printf("%s\n", p);*/
    puts(p);
    printf("%lu\n", strlen(p));
    free(p);
    return 0;
}
