#include <stdio.h>
int main() {
    int i;
    char a[] = "abcde", b[6];
    // should be for (i = 0; i < 6; i++)
    for (i = 0; i < 5; i++)
        b[i] = a[i];
    printf("%s", b);
    /*    printf("\n");*/
    return 0;
}
