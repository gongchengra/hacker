/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 86_eof_not_character.c
* Author : gongchengra@gmail.com
* Purpose : https://ruslanspivak.com/eofnotchar/
* Creation Date : 2020-05-09
* Last Modified : 2020-05-09 11:01:55+0800
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
void printeof() {
    printf("EOF value on my system: %d\n", EOF);
}
int main(int argc, char **argv) {
    printeof();
    FILE *fp;
    int c;
    if ((fp = fopen(*++argv, "r")) == NULL) {
        printf("mcat: can't open %s\n", *argv);
        return 1;
    }
    while ((c = getc(fp)) != EOF)
        putc(c, stdout);
    fclose(fp);
    return 0;
}
