#include <stdio.h>
int main() {
    int i;
    char str[256];
    i = -1;
    do {
        i++;
        scanf("%c", &str[i]);
    } while (str[i] != '#');
    str[i] = '\0';
    printf("%s\n", str);
    scanf("%s", str);
    printf("%s\n", str);
}
