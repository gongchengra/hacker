/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : eg_05_06_mem.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2020-04-17
* Last Modified :
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINES 5000
char *lineptr[MAXLINES];
int readlines(char *lineptr[], int maxlines) {
    size_t len, nlines = 0;
    char *p, *line = NULL;
    while ((len = getline(&line, &len, stdin)) != -1) {
        p = malloc(len * sizeof(char));
        if (nlines >= maxlines || p == NULL) {
            return -1;
        } else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}
int cmp(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}
void writelines(char *lineptr[], int nlines) {
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}
int main(int argc, char **argv) {
    int nlines;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, nlines, sizeof(char *), cmp);
        writelines(lineptr, nlines);
        return 0;
    }
}
