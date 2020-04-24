/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : eg_06_03_count_keywords.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2020-04-19
* Last Modified : 2020-04-19 20:22:10+0800
_._._._._._._._._._._._._._._._._._._._._.*/
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define BUFSIZE 100
#define MAXWORD 100
#define NKEYS (sizeof(keytab) / sizeof(keytab[0]))
struct key {
    char *word;
    int count;
} keytab[] = {{"auto", 0},     {"break", 0},    {"case", 0},     {"char", 0},
              {"const", 0},    {"continue", 0}, {"default", 0},  {"do", 0},
              {"double", 0},   {"else", 0},     {"enum", 0},     {"extern", 0},
              {"float", 0},    {"for", 0},      {"goto", 0},     {"if", 0},
              {"int", 0},      {"long", 0},     {"register", 0}, {"return", 0},
              {"short", 0},    {"signed", 0},   {"sizeof", 0},   {"static", 0},
              {"struct", 0},   {"switch", 0},   {"typedef", 0},  {"union", 0},
              {"unsigned", 0}, {"void", 0},     {"volatile", 0}, {"while", 0}};
int getword(char *word, int lim) {
    int c;
    char *w = word;
    short in_comment = 0;
    while (isspace(c=getchar()));
    if (c != EOF) *w++ = c;
    if (!isalpha(c)) {*w = '\0'; return c;}
    for (; --lim > 0; w++) {
        if (!isalnum(*w = getchar())) {
            ungetc(*w, stdin);
            break;
        }
    }
    *w = '\0';
    return word[0];
}
int binsearch(char *word, struct key tab[], int n) {
    int cond, lo=0, hi=n-1, mid;
    while (lo <= hi) {
        mid = (lo + hi) /2;
        if ((cond = strcmp(word, tab[mid].word)) < 0) {
            hi = mid -1;
        } else if (cond > 0) {
            lo = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}
int main(int argc, char **argv){
    int n;
    char word[MAXWORD];
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha((unsigned char)word[0])) {
            if ((n = binsearch(word, keytab, NKEYS)) >= 0) {
                keytab[n].count++;
            }
        }
    }
    for (n = 0; n < NKEYS; n++) {
        if(keytab[n].count > 0) {
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
        }
    }
    return 0;
}
