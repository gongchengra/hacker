#include <stdio.h>
#include <stdlib.h>
struct node {
    char item;
    struct node* l;
    struct node* r;
};
struct node* new_node(char item) {
    struct node* t = malloc(sizeof(struct node));
    t->item = item;
    t->r = t->l = NULL;
    return t;
}
void add_left_leaf(struct node* parent, char item) { parent->l = new_node(item); }
void add_right_leaf(struct node* parent, char item) { parent->r = new_node(item); }
void traverse(struct node* h, void (*visit)(struct node*)) {
    if (h == NULL)
        return;
    (*visit)(h);
    traverse(h->l, visit);
    traverse(h->r, visit);
}
void print_item(char x) { printf("%c ", x); }
void print_node(struct node* node) { print_item(node->item); }
/*
                E
              /   \
             /     \
            D       H
           / \     / \
          B       F
         / \     / \
        A   C       G
       / \ / \     / \
*/
int main(void) {
    struct node* root;
    struct node* left;
    struct node* right;
    root = new_node('E');
    add_left_leaf(root, 'D');
    add_right_leaf(root, 'H');
    left = root->l;
    add_left_leaf(left, 'B');
    left = left->l;
    add_left_leaf(left, 'A');
    add_right_leaf(left, 'C');
    right = root->r;
    add_left_leaf(right, 'F');
    right = right->l;
    add_right_leaf(right, 'G');
    traverse(root, print_node);
    printf("\n");
    return 0;
}
