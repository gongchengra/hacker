/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 79_getline_example.c
* Author : gongchengra@gmail.com
* Purpose : https://c-for-dummies.com/blog/?p=1112
* Purpose : http://man7.org/linux/man-pages/man3/getline.3.html
* Creation Date : 2020-04-17
* Last Modified :
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
#include <stdlib.h>
#if 0
// https://c-for-dummies.com/blog/?p=1112
int main(int argc, char **argv) {
    char *buffer;
    size_t bufsize = 32;
    size_t characters;
    buffer = (char *)malloc(bufsize * sizeof(char));
    if (buffer == NULL) {
        perror("Unable to allocate buffer");
        exit(1);
    }
    printf("Type something: ");
    characters = getline(&buffer, &bufsize, stdin);
    printf("%zu characters were read.\n", characters);
    printf("You typed: %s", buffer);
    return (0);
}
#endif
#if 1
// http://man7.org/linux/man-pages/man3/getline.3.html
int main(int argc, char *argv[]) {
    FILE *stream;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    stream = fopen(argv[1], "r");
    if (stream == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    while ((nread = getline(&line, &len, stream)) != -1) {
        printf("Retrieved line of length %zu:\n", nread);
        fwrite(line, nread, 1, stdout);
    }
    free(line);
    fclose(stream);
    exit(EXIT_SUCCESS);
}
#endif
