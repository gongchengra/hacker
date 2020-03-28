#include <stdio.h>
#include <string.h>
char *mycopy(char *dest, char *src) {
    if (dest == NULL || src == NULL)
        return dest;
    while ((*dest++ = *src++))
        ;
    return dest;
}
int main() {
    char s1[16];
    char s2[16] = "how are you?";
    char s3[16];
    mycopy(s1, s2);
    strcpy(s3, s2);
    printf("%s",s1);
    printf("\n");
    printf("%s",s3);
    printf("\n");
}
