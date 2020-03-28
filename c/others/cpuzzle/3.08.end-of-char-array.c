#include <stdio.h>
int main() {
    int i = 0;
    char a[] = "How are you?", b[13];
    while (a[i] != '\0') {
        b[i] = a[i];
        ++i;
    }
    /*    b[i] = '\0';*/
    /*    i = -1;*/
    /*    while (i++, b[i] != '\0')*/
    /*        printf("%c ", b[i]);*/
    for (i = 0; b[i] != '\0'; i++)
        printf("%c ", b[i]);
    printf("\n");
    return 0;
}
