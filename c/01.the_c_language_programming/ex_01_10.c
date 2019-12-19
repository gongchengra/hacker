#include <stdio.h>

int main()
{
    int c;
    //setbuf(stdin, NULL);
    //setvbuf(stdout, NULL, _IONBF, BUFSIZ);
    do {
        //fflush(stdout);
        if (c == '\\') {
            putchar('\\');
            putchar('\\');
        } else if (c == '\t') {
            putchar('\\');
            putchar('t');
        } else if (c == '\b') {
            putchar('\\');
            putchar('b');
        } else {
            putchar(c);
        }
    } while ( (c=getchar()) != EOF);
    return 0;
}
