#include <stdio.h>
/* maximum input line length */
#define MAXLINE 1000

/* getline: read a line into s, return length */
int getlines(char s[],int lim) {
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
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

