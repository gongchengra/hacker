#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int i = 0;
    char t[] = "abcde";
    char *p;
    /*  wrong  if ((p = malloc(strlen(t))) == NULL) {*/
    if ((p = malloc(strlen(t) + 1)) == NULL) {
        printf("内存分配错误!\n");
        exit(1);
    }
    while ((p[i] = t[i]) != '\0')
        i++;
    printf("%s\n", p);
    free(p);
    return 0;
}
