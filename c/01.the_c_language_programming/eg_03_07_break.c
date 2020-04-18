#include <stdio.h>
#include <string.h>
/* trim: remove trailing blanks, tabs, newlines */
int trim(char s[]) {
    int n;
    for (n = strlen(s) - 1; n >= 0; n--)
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
            break;
    s[n + 1] = '\0';
    return n;
}
int main() {
    char ts[] = "test    ";
    printf("%s, %ld\n", ts, sizeof(ts) / sizeof(char));
    printf("%s, %ld\n", ts, strlen(ts));
    trim(ts);
    printf("%s, %ld\n", ts, sizeof(ts) / sizeof(char));
    printf("%s, %ld\n", ts, strlen(ts));
}
