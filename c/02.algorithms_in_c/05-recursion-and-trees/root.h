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
link init() {
    link root, left, right;
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
    return root;
}
