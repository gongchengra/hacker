#include <stdio.h>
#include <stdlib.h>
typedef struct tnode *link;
struct tnode {
    char token;
    link l, r;
};
link new (char token, link l, link r) {
    link x = malloc(sizeof(*x));
    x->token = token;
    x->r = r;
    x->l = l;
    return x;
}
int i = 0;
char a[] = "*+a**bc+def";
link parse() {
    char t = a[i++];
    link x = new (t, NULL, NULL);
    if ((t == '+') || (t == '*')) {
        x->l = parse();
        x->r = parse();
    }
    return x;
}
void printnode(char c, int h) {
    int i;
    for (i = 0; i < h; i++)
        printf("    ");
    printf("%c\n", c);
}
void show(link x, int h) {
    if (x == NULL) {
        printnode(' ', h);
        return;
    }
    show(x->r, h + 1);
    printnode(x->token, h);
    show(x->l, h + 1);
}
int main(void) {
    link root = parse();
    show(root, 1);
    return 0;
}
