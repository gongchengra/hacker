#include <ctype.h>
#include <getopt.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
    int opt, flag=0;
    while ((opt = getopt(argc, argv, "uUlL")) != EOF) {
        switch (opt) {
            case 'u':
            case 'U':
                flag = 1;
                break;
            case 'l':
            case 'L':
                flag = 2;
                break;
        }
    }
    int c;
    while ((c = getchar()) != EOF) {
        if (flag == 1) {
            putchar(toupper(c));
        } else {
            putchar(tolower(c));
        }
    }
    return 0;
}
