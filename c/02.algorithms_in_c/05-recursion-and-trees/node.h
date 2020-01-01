typedef char Item;
typedef struct node* link;
struct node {
    Item val;
    link l;
    link r;
};
link new_node(Item val) {
    link t = malloc(sizeof *t);
    t->val = val;
    t->r = NULL;
    t->l = NULL;
    return t;
}
void add_left_leaf(link parent, Item val) { parent->l = new_node(val); }
void add_right_leaf(link parent, Item val) { parent->r = new_node(val); }
void print_item(Item x) { printf("%c ", x); }
void print_node(link node) { print_item(node->val); }
