#include <stdio.h>
#include <string.h>
int main() {
    int i, a[5] = {1, 2, 3, 4, 5}, b[5];
    char ch[] = "good!", st[6];
    /* wrong b = a;*/
    for (i = 0; i < 5; i++)
        b[i] = a[i];
    /* wrong st = ch;*/
    // right way 1
    /*    for (i = 0; i < 6; i++)*/
    /*        st[i] = ch[i];*/
    // right way 2
    strcpy(st, ch);
    for (i = 0; i < 5; i++)
        printf("%d ", b[i]);
    printf("\n");
    printf("%s", st);
    printf("\n");
    return 0;
}
