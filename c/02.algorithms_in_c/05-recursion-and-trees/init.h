/*
                         0
                    _____|_____
                   /  /  |  \  \
                  /  /   |   \  \
                 /   1---7---2   \
                /        |        6
                5----3   |       /
                 \    \ /       /
                  \____4_______/
  0 -> 7 -> 5 -> 2 -> 1 -> 6
  1 -> 7 -> 0
  2 -> 7 -> 0
  3 -> 5 -> 4
  4 -> 6 -> 5 -> 7 -> 3
  5 -> 0 -> 4 -> 3
  6 -> 4 -> 0
  7 -> 1 -> 2 -> 0 -> 4
 */
int visited[N];
nlink *adj;
nlink *make_list(void) {
    nlink *l;
    l = malloc(N * sizeof(l));
    l[0] =
        new_node(7, new_node(5, new_node(2, new_node(1, new_node(6, NULL)))));
    l[1] = new_node(7, new_node(0, NULL));
    l[2] = new_node(7, new_node(0, NULL));
    l[3] = new_node(5, new_node(4, NULL));
    l[4] = new_node(6, new_node(5, new_node(7, new_node(3, NULL))));
    l[5] = new_node(0, new_node(4, new_node(3, NULL)));
    l[6] = new_node(4, new_node(0, NULL));
    l[7] = new_node(1, new_node(2, new_node(0, new_node(4, NULL))));
    return l;
}
void print_list_array(nlink *l, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d -> ", i);
        while (l[i] != NULL) {
            printf("%d ", l[i]->v);
            l[i] = l[i]->next;
        }
        printf("\n");
    }
}
void print_val(int k) { printf("%d ", k); }

