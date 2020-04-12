#include <stdio.h>
#include <string.h>
int main(int argc, char **argv) {
    char s1[100] = "Programming is ", s2[] = "fun.";
    int i = 0, j = 0;
#if 0
    for (i = 0; s1[i] != '\0'; i++)
        ;
    for (j = 0; s2[j] != '\0'; i++, j++)
        s1[i] = s2[j];
    s1[i] = '\0';
#endif
#if 0
    while (s1[i] != '\0')
        i++;
    while ((s1[i++] = s2[j++]) != '\0')
        ;
    s1[i] = '\0';
#endif
    strcat(s1, s2);
    printf("%s", s1);
    return 0;
}
