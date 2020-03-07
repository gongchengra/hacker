#include <stdio.h>
int dive(int, int);
int main() {
    int a = 550, b = 2;
    const int k = 2;
    extern char str[];
    printf("%s%d\n", str, k * dive(a, b));
    return 0;
}
