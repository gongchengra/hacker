/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 81_binary_tree.c
* Author : gongchengra@gmail.com
* Purpose : write a binary tree
* Creation Date : 2020-04-20
* Last Modified : 2020-04-20 13:41:26+0800
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct tnode *node;
struct tnode {
    int val;
    node left;
    node right;
};
node addtree(node p, int n) {
    if (p == NULL) {
        p = (node)malloc(sizeof(struct tnode));
        if (p == NULL) {
            printf("No memory.");
            exit(1);
        }
        p->val = n;
        p->left = p->right = NULL;
    }
    if (p->val > n) {
        p->left = addtree(p->left, n);
    }
    if (p->val < n) {
        p->right = addtree(p->right, n);
    }
    return p;
}
int printree(node p) {
    static int c = 0;
    if (p != NULL) {
        printree(p->left);
        printf("%4d", p->val);
        c++;
        printree(p->right);
    }
    return c;
}
#define size 10
#define max 100
int main(int argc, char **argv) {
    srand(time(NULL));
    node root = NULL;
    for (int i = 0; i < 2 * size; i++) {
        int v = rand() % max;
        root = addtree(root, v);
    }
    int c = printree(root);
    printf("\n");
    printf("%d", c);
    return 0;
}
