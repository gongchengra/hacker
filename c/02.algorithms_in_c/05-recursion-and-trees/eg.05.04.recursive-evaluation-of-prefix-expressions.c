#include <stdio.h>
char *a;
int i;
int eval() {
    int x = 0;
    while (a[i] == ' ')
        i++;
    if (a[i] == '+') {
        i++;
        return eval() + eval();
    }
    if (a[i] == '*') {
        i++;
        return eval() * eval();
    }
    while ((a[i] >= '0') && (a[i] <= '9'))
        x = 10 * x + (a[i++] - '0');
    return x;
}
int main(int argc, char *argv[]) {
    a = argv[1];
    printf("%d\n", eval());
    return 0;
}
