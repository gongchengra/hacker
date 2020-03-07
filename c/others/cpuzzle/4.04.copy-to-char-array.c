#include <stdio.h>
int main() {
    char s[32], *t = " You are welcome!";
    int i = 0;
    while ((s[i++] = *t++));
    printf("%s\n", s);
}
