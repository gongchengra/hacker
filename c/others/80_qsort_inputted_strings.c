/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : t.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2020-04-17
* Last Modified :
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}
#define max 100
int main(int argc, char **argv) {
    char *lines[max], *buffer = NULL, *p;
    size_t len, bufsize = 0, nline = 0;
    while ((len = getline(&buffer, &bufsize, stdin)) != -1) {
        if (nline > max) {
            printf("Too many lines.");
            return 1;
        } else {
            buffer[len - 1] = '\0';
            p = malloc(len * sizeof(char));
            strcpy(p, buffer);
            if (strcmp(p, "EOF") == 0){
                break;
            }
            lines[nline++] = p;
        }
    }
    qsort(lines, nline, sizeof(char *), cmp);
    for (int i = 0; i < nline; i++) {
        printf("%s\n", lines[i]);
    }
    free(buffer);
    return 0;
}
