typedef struct node *nlink;
struct node {
    int v;
    nlink next;
};
nlink new_node(int v, nlink next) {
    nlink x = malloc(sizeof *x);
    x->v = v;
    x->next = next;
    return x;
}
