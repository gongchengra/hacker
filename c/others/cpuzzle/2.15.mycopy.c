#include <stdio.h>
char s1[16];
char *mycopy(char *dest, char *src) {
    if (dest == NULL || src == NULL)
        return dest;
    while ((*dest++ = *src++))
        ;
    return dest;
}
int main() {
    char s2[16] = "how are you?";
    mycopy(s1, s2);
    printf("%s",s1);
    printf("\n");
}
