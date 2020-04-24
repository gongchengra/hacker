/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : eg_06_05_self_referential_struct.c
* Author : gongchengra@gmail.com
* Purpose : count words
* Creation Date : 2014-11-28
* Last Modified : 2020-04-20 10:21:08+0800
_._._._._._._._._._._._._._._._._._._._._.*/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 100
#define MAXWORD 100
char buf[BUFSIZE];
int bufp = 0;
struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
/* word frequency count */
int main(void) {
    struct tnode *root;
    char word[MAXWORD];
    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);
    treeprint(root);
    return 0;
}
/* talloc: make a tnode */
struct tnode *talloc(void) {
    return (struct tnode *)malloc(sizeof(struct tnode));
}
/* make a duplicate of s */
char *strdupkr(char *s) {
    char *p;
    p = (char *)malloc(strlen(s) + 1); /* +1 for '\0' */
    if (p != NULL)
        strcpy(p, s);
    return p;
}
/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w) {
    int cond;
    if (p == NULL) {  /* a new word has arrived */
        p = talloc(); /* make a new node */
        p->word = strdupkr(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;    /* repeated word */
    else if (cond < 0) /* less than into left subtree */
        p->left = addtree(p->left, w);
    else /* greater than into right subtree */
        p->right = addtree(p->right, w);
    return p;
}
/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p) {
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}
int getword(char *word, int lim) {
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    short in_comment = 0;
    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}
int getch(void) { return (bufp > 0 ? buf[--bufp] : getchar()); }
void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
