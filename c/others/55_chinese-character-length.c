#include <stdio.h>
#include <string.h>
int main() {
    char c[] = "数学";
    printf("%lu\n", strlen(c));
    printf("%s\n", c);
    char a[] = "ab";
    printf("%lu\n", strlen(a));
    printf("%s\n", a);
    return 0;
}
