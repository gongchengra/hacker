#include <stdio.h>
int main() {
    int c;
    while ((c = getchar()) != '\n') {
        /*    while ((c = getchar()) != EOF) {*/
        putchar(c);
    }
}
