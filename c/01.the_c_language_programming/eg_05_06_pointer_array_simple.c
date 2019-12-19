#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 50
int main() {
    char *lineptr[MAXLINE];
    lineptr[0] = "Chapter 1\n";
    lineptr[1] = "Chapter 2\n";
    lineptr[2] = "Chapter 3\n";
    lineptr[3] = "Chapter 4\n";
    lineptr[4] = "Chapter 5\n";
    for (int i = 0; (lineptr[i] != NULL) && i < MAXLINE; i++) {
        if (strlen(lineptr[i]) > 0) {
            //printf("%s\n", lineptr[i]);
            for(int j = 0;j < strlen(lineptr[i]);j++){
                printf("%c", *(lineptr[i]+j));
            }
        }
    }
    return 0;
}
