#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFERSIZE 10
int main() {
    char *text = calloc(1, 1), buffer[BUFFERSIZE];
    printf("Enter a message: \n");
    while (fgets(buffer, BUFFERSIZE, stdin)) /* break with ^D or ^Z */
    {
        text = realloc(text, strlen(text) + 1 + strlen(buffer));
        if (!text)
            return 1;
        strcat(text, buffer); /* note a '\n' is appended here everytime */
        printf("%s\n", buffer);
    }
    printf("\ntext:\n%s", text);
    return 0;
}
