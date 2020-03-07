#include <stdio.h>
int main() {
    int i, nother;
    char c;
    int ndigit[10], nchar[26];
    nother = 0;
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;
    for (i = 0; i < 26; ++i)
        nchar[i] = 0;
    while ((c = getchar()) != '\n')
        if (c >= '0' && c <= '9')
            ++ndigit[c - '0'];
        else if (c >= 'a' && c <= 'z')
            ++nchar[c - 'a'];
        else if (c >= 'A' && c <= 'Z')
            ++nchar[c - 'A'];
        else
            ++nother;
    printf("digits:\n");
    for (i = 0; i < 10; i++)
        printf("%3d ", i);
    printf("\n");
    for (i = 0; i < 10; ++i)
        printf("%3d ", ndigit[i]);
    printf("\ncharacters:\n");
    for (i = 0; i < 26; ++i)
        printf("%3c ", 'a'+i);
    printf("\n");
    for (i = 0; i < 26; ++i)
        printf("%3d ", nchar[i]);
    printf("\nother= %d\n", nother);
}
