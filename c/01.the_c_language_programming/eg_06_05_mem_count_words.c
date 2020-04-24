/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : eg_06_05_mem_count_words.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2020-04-20
* Last Modified : 2020-04-20 13:00:05+0800
_._._._._._._._._._._._._._._._._._._._._.*/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXWORD 100
typedef struct tnode *node;
struct tnode {
    char *word;
    int count;
    node left;
    node right;
};
node addtree(node p, char *w) {
    int cond;
    if (p == NULL) {
        p = (node)malloc(sizeof(struct tnode));
        char *copy = (char *)malloc(strlen(w) + 1);
        if(copy == NULL) {
            printf("No memory.");
            exit(1);
        }
        strcpy(copy, w);
        p->word = copy;
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) {
        p->count++;
    } else if (cond < 0) {
        p->left = addtree(p->left, w);
    } else {
        p->right = addtree(p->right, w);
    }
    return p;
}
int getword(char *word, int lim) {
    char c, *w = word;
    while (isspace(c = getchar()))
        ;
    if (c != EOF) {
        *w++ = c;
    }
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++) {
        if (!isalnum(*w = getchar())) {
            ungetc(*w, stdin);
            break;
        }
    }
    *w = '\0';
    return word[0];
}
void treeprint(node p) {
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}
int main(int argc, char **argv) {
    node root;
    char word[MAXWORD];
    root = NULL;
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            root = addtree(root, word);
        }
    }
    treeprint(root);
    return 0;
}
