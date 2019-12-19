#include <stdio.h>
/* maximum input line length */
#define MAXLINE 1000

/* Reverse the string. */
int reverse(char s[],int lim) {
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int main() {
    int len;
    /* current line length */
    char line[MAXLINE];
    /* current input line */
    char lastchar;
    while ((len = getlines(line, MAXLINE)) > 0){
        while(len > 1 && (line[len-2] == ' ' || line[len-2] == '\t')) {
            line[len-2] = '\n';
            len--;
        }
        if(len > 1) {
            printf("%d, %s", len, line);
        }
    }
    return 0;
}

