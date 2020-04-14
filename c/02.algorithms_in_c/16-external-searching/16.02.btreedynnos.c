/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 16.02.btreedynnos.c
* Author : gongchengra@gmail.com
* Purpose : https://gist.github.com/yorickdewid/d86e14cb2f3929823841
* Creation Date : 2020-04-10
* Last Modified :
_._._._._._._._._._._._._._._._._._._._._.*/
/*
 * Btree example for DynnOS
 *
 * Quenza simple license
 * 2013, Dinux
 *
 *
 */
/*
** B-Tree definition :
** Assume the degree of the tree is d(d>=2).
**   1. Every node has at most 2d children.
**   2. Every node (except root) has at least d children.
**   3. The root has at least 2 children if it is not a leaf node.
**   4. A non-leaf node with K children contains K-1 keys. And :
**      K[1]<=K[2]<=K[3]<=...<=K[K-1].
**   5. All leaves appear in the same level.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define EMPTY 0
#define NODE_ORDER 3 /*The degree of the tree.*/
#define NODE_POINTERS (NODE_ORDER * 2)
#define NODE_KEYS NODE_POINTERS - 1
typedef unsigned char bool;
typedef struct tree_node {
    int key_array[NODE_KEYS];
    struct tree_node *child_array[NODE_POINTERS];
    unsigned int key_index;
    bool leaf;
} node_t;
typedef struct {
    node_t *node_pointer;
    int key;
    bool found;
    unsigned int depth;
} result_t;
typedef struct {
    node_t *root;
    unsigned short order;
    bool lock;
} btree_t;
static int BTreeGetLeftMax(node_t *T);
static int BTreeGetRightMin(node_t *T);
/* The AllocateNode operation allocate a b-tree node.And then set the node's
** properties to the defualt value :
**   BTreeNode => K[i] = 0
**   BTreeNode => child_array[i] = NULL
**   BTreeNode => key_index = 0
**   BTreeNode => isLeaf = 1;
*/
static node_t *create_node() {
    int i;
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (!new_node) {
        printf("Out of memory");
        exit(0);
    }
    // Set Keys
    for (i = 0; i < NODE_KEYS; i++) {
        new_node->key_array[i] = 0;
    }
    // Set ptr
    for (i = 0; i < NODE_POINTERS; i++) {
        new_node->child_array[i] = NULL;
    }
    new_node->key_index = EMPTY;
    new_node->leaf = TRUE;
    return new_node;
}
/* The CreatBTree operation creates an empty b-tree by allocating a new root
** that has no keys and is a leaf node.Only the root node is permitted to
** have this properties.
*/
btree_t *create_btree() {
    btree_t *new_root = (btree_t *)malloc(sizeof(btree_t));
    if (!new_root) {
        return NULL;
    }
    node_t *head = create_node();
    if (!head) {
        return NULL;
    }
    new_root->order = NODE_ORDER;
    new_root->root = head;
    new_root->lock = FALSE;
    return new_root;
}
static result_t *get_resultset() {
    result_t *ret = (result_t *)malloc(sizeof(result_t));
    if (!ret) {
        printf("ERROR! Out of memory.");
        exit(0);
    }
    ret->node_pointer = NULL;
    ret->key = 0;
    ret->found = FALSE;
    ret->depth = 0;
    return ret;
}
void print_node(node_t *n) {
    int i, q;
    printf(">>-----0x%x-----\n", (int)n);
    printf("  Index: %d\n", n->key_index);
    printf("   Leaf: ");
    if (n->leaf) {
        printf("TRUE\n");
    } else {
        printf("FALSE\n");
    }
    printf("  Array:");
    for (i = 0; i < n->key_index; i++) {
        printf(" [%d : %d]", i, n->key_array[i]);
    }
    printf("\n  Child:");
    if (n->leaf) {
        printf(" NONE");
    } else {
        for (q = 0; q < NODE_POINTERS; q++) {
            printf(" [%d : %x]", q, (int)n->child_array[q]);
        }
    }
    printf("\n<<------------------\n");
}
/* The BTreeSearch operation is to search X in T.Recursively traverse the tree
** from top to bottom.At each level, BTreeSearch choose the maximum key whose
** value is greater than or equal to the desired value X.If equal to the
** desired ,found.Otherwise continue to traverse.
*/
result_t *search(int key, node_t *node) {
    print_node(node);
    int i = 0;
    while ((i < node->key_index) && (key > node->key_array[i])) {
        // printf("it %d is <= %d and key %d > than %d\n", i, node->key_index,
        // key, node->key_array[i]);
        i++;
    }
    // printf("end iterator: %d\n", i);
    // printf("better: \n");
    /*
            int c = 0;
            while((c < node->key_index) && (key > node->key_array[c])){
                    printf("it %d is <= %d and key %d > than %d\n", c,
       node->key_index, key, node->key_array[c]); c++;
            }
    */
    // HACK /// may not be working
    if (i == 6) {
        i--;
    }
    // Check if we found it
    if ((i <= node->key_index) && (key == node->key_array[i])) {
        result_t *result = get_resultset();
        result->node_pointer = node;
        result->key = i;
        result->found = TRUE;
        return result;
    }
    // Not found check leaf or child
    if (node->leaf) {
        result_t *result = get_resultset();
        result->node_pointer = node;
        result->found = FALSE;
        return result;
    } else {
        result_t *result = get_resultset();
        return search(key, node->child_array[i]);
    }
}
/* The split_child operation moves the median key of node child_array into
** its parent ptrParent where child_array is the ith child of ptrParent.
*/
static void split_child(node_t *parent_node, int i, node_t *child_array) {
    int j;
    // Allocate a new node to store child_array's node.
    node_t *new_node = create_node();
    new_node->leaf = child_array->leaf;
    new_node->key_index = NODE_ORDER - 1;
    // Move child_array's right half nodes to the new node.
    for (j = 0; j < NODE_ORDER - 1; j++) {
        new_node->key_array[j] = child_array->key_array[NODE_ORDER + j];
    }
    // If child_array is not leaf node,then move child_array's [child_array]s to
    // the new node's [child_array]s.
    if (child_array->leaf == 0) {
        for (j = 0; j < NODE_ORDER; j++) {
            new_node->child_array[j] = child_array->child_array[NODE_ORDER + j];
        }
    }
    child_array->key_index = NODE_ORDER - 1;
    // Right shift ptrParent's [child_array] from index i
    for (j = parent_node->key_index; j >= i; j--) {
        parent_node->child_array[j + 1] = parent_node->child_array[j];
    }
    // Set ptrParent's ith child_array to the newNode.
    parent_node->child_array[i] = new_node;
    // Right shift ptrParent's Keys from index i-1
    for (j = parent_node->key_index; j >= i; j--) {
        parent_node->key_array[j] = parent_node->key_array[j - 1];
    }
    // Set ptrParent's [i-1]th Key to child_array's median [child_array]
    parent_node->key_array[i - 1] = child_array->key_array[NODE_ORDER - 1];
    // Increase ptrParent's Key number.
    parent_node->key_index++;
}
/* The BTreeInsertNonFull operation insert X into a non-full node T.before
** execute this operation,guarantee T is not a full node.
*/
static void insert_nonfull(node_t *n, int key) {
    int i = n->key_index;

    if (n->leaf) {
        // Shift until we fit
        while (i >= 1 && key < n->key_array[i - 1]) {
            n->key_array[i] = n->key_array[i - 1];
            i--;
        }
        n->key_array[i] = key;
        n->key_index++;
    } else {
        // Find the position i to insert.
        while (i >= 1 && key < n->key_array[i - 1]) {
            i--;
        }
        // If T's ith child_array is full,split first.
        if (n->child_array[i]->key_index == NODE_KEYS) {
            split_child(n, i + 1, n->child_array[i]);
            if (key > n->key_array[i]) {
                i++;
            }
        }
        // Recursive insert.
        insert_nonfull(n->child_array[i], key);
    }
}
/* The BTreeInsert operation insert key into T.Before insert ,this operation
** check whether T's root node is full(root->key_index == 2*d -1) or not.If
*full,
** execute split_child to guarantee the parent never become full.And then
** execute BTreeInsertNonFull to insert X into a non-full node.
*/
node_t *insert(int key, btree_t *b) {
    if (!b->lock) {
        node_t *root = b->root;
        if (root->key_index == NODE_KEYS) { // If node root is full,split it.
            node_t *newNode = create_node();
            b->root = newNode; // Set the new node to T's Root.
            newNode->leaf = 0;
            newNode->key_index = 0;
            newNode->child_array[0] = root;
            split_child(newNode, 1, root); // Root is 1th child of newNode.
            insert_nonfull(newNode, key);  // Insert X into non-full node.
        } else {                           // If not full,just insert X in T.
            insert_nonfull(b->root, key);
        }
    } else {
        printf("Tree is locked\n");
    }
    return b->root;
}
/* The merge_children operation merge the root->K[index] and its two child
** and then set chlid1 to the new root.
*/
static void merge_children(node_t *root, int index, node_t *child1,
                           node_t *child2) {
    child1->key_index = NODE_KEYS;
    int i;
    // Move child2's key to child1's right half.
    for (i = NODE_ORDER; i < NODE_KEYS; i++)
        child1->key_array[i] = child2->key_array[i - NODE_ORDER];
    child1->key_array[NODE_ORDER - 1] =
        root->key_array[index]; // Shift root->K[index] down.
    // If child2 is not a leaf node,must copy child2's [ptrchlid] to the new
    // root(child1)'s [child_array].
    if (0 == child2->leaf) {
        for (i = NODE_ORDER; i < NODE_POINTERS; i++)
            child1->child_array[i] = child2->child_array[i - NODE_ORDER];
    }
    // Now update the root.
    for (i = index + 1; i < root->key_index; i++) {
        root->key_array[i - 1] = root->key_array[i];
        root->child_array[i] = root->child_array[i + 1];
    }
    root->key_index--;
    free(child2);
}
/* The BTreeBorrowFromLeft operation borrows a key from leftPtr.curPtr borrow
** a node from leftPtr.root->K[index] shift down to curPtr,shift leftPtr's
** right-max key up to root->K[index].
*/
static void BTreeBorrowFromLeft(node_t *root, int index, node_t *leftPtr,
                                node_t *curPtr) {
    curPtr->key_index++;
    int i;
    for (i = curPtr->key_index - 1; i > 0; i--)
        curPtr->key_array[i] = curPtr->key_array[i - 1];
    curPtr->key_array[0] = root->key_array[index];
    root->key_array[index] = leftPtr->key_array[leftPtr->key_index - 1];
    if (0 == leftPtr->leaf)
        for (i = curPtr->key_index; i > 0; i--)
            curPtr->child_array[i] = curPtr->child_array[i - 1];
    curPtr->child_array[0] = leftPtr->child_array[leftPtr->key_index];
    leftPtr->key_index--;
}
/* The BTreeBorrowFromLeft operation borrows a key from rightPtr.curPtr borrow
** a node from rightPtr.root->K[index] shift down to curPtr,shift RightPtr's
** left-min key up to root->K[index].
*/
static void BTreeBorrowFromRight(node_t *root, int index, node_t *rightPtr,
                                 node_t *curPtr) {
    curPtr->key_index++;
    curPtr->key_array[curPtr->key_index - 1] = root->key_array[index];
    root->key_array[index] = rightPtr->key_array[0];
    int i;
    for (i = 0; i < rightPtr->key_index - 1; i++)
        rightPtr->key_array[i] = rightPtr->key_array[i + 1];
    if (0 == rightPtr->leaf) {
        curPtr->child_array[curPtr->key_index] = rightPtr->child_array[0];
        for (i = 0; i < rightPtr->key_index; i++)
            rightPtr->child_array[i] = rightPtr->child_array[i + 1];
    }
    rightPtr->key_index--;
}
/* The BTreeDeleteNoNone operation recursively delete X in root,handle both leaf
** and internal node:
**   1. If X in a leaf node,just delete it.
**   2. If X in a internal node P:
**      a): If P's left neighbor -> prePtr has at least d keys,replace X with
**      	prePtr's right-max key and then recursively delete it.
**      b): If P's right neighbor -> nexPtr has at least d keys,replace X with
**      	nexPtr's left-min key and then recursively delete it.
**      c): If both of prePtr and nexPtr have d-1 keys,merge X and nexPtr into
**      	prePtr.Now prePtr have 2*d-1 keys,and then recursively delete X
*in
**      	prePtr.
**   3. If X not in a internal node P,X must in P->child_array[i] zone.If
*child_array[i]
**      only has d-1 keys:
**      a): If child_array[i]'s neighbor have at least d keys,borrow a key from
**      	child_array[i]'s neighbor.
**      b): If both of child_array[i]'s left and right neighbor have d-1
*keys,merge
**      	child_array[i] with one of its neighbor.
**      finally,recursively delete X.
*/
static void BTreeDeleteNoNone(int X, node_t *root) {
    int i;
    // Is root is a leaf node ,just delete it.
    if (1 == root->leaf) {
        i = 0;
        while ((i < root->key_index) &&
               (X > root->key_array[i])) // Find the index of X.
            i++;
        // If exists or not.
        if (X == root->key_array[i]) {
            for (; i < root->key_index - 1; i++)
                root->key_array[i] = root->key_array[i + 1];
            root->key_index--;
        } else {
            printf("Node not found.\n");
            return;
        }
    } else { // X is in a internal node.
        i = 0;
        node_t *prePtr = NULL, *nexPtr = NULL;
        // Find the index;
        while ((i < root->key_index) && (X > root->key_array[i]))
            i++;
        if ((i < root->key_index) &&
            (X == root->key_array[i])) { // Find it in this level.
            prePtr = root->child_array[i];
            nexPtr = root->child_array[i + 1];
            /*If prePtr at least have d keys,replace X by X's precursor in
             *prePtr*/
            if (prePtr->key_index > NODE_ORDER - 1) {
                int aPrecursor = BTreeGetLeftMax(prePtr);
                root->key_array[i] = aPrecursor;
                // Recursively delete aPrecursor in prePtr.
                BTreeDeleteNoNone(aPrecursor, prePtr);
            } else if (nexPtr->key_index > NODE_ORDER - 1) {
                /*If nexPtr at least have d keys,replace X by X's successor in
                 * nexPtr*/
                int aSuccessor = BTreeGetRightMin(nexPtr);
                root->key_array[i] = aSuccessor;
                BTreeDeleteNoNone(aSuccessor, nexPtr);
            } else {
                /*If both of root's two child have d-1 keys,then merge
                 * root->K[i] and prePtr nexPtr. Recursively delete X in the
                 * prePtr.*/
                merge_children(root, i, prePtr, nexPtr);
                BTreeDeleteNoNone(X, prePtr);
            }
        } else { // Not find in this level,delete it in the next level.
            prePtr = root->child_array[i];
            node_t *leftBro = NULL;
            if (i < root->key_index)
                nexPtr = root->child_array[i + 1];
            if (i > 0)
                leftBro = root->child_array[i - 1];
            /*root->child_array[i] need to borrow from or merge with his
             * neighbor and then recursively delete. */
            if (NODE_ORDER - 1 == prePtr->key_index) {
                // If left-neighbor have at least d-1 keys,borrow.
                if ((leftBro != NULL) && (leftBro->key_index > NODE_ORDER - 1))
                    BTreeBorrowFromLeft(root, i - 1, leftBro, prePtr);
                else // Borrow from right-neighbor
                    if ((nexPtr != NULL) &&
                        (nexPtr->key_index > NODE_ORDER - 1))
                    BTreeBorrowFromRight(root, i, nexPtr, prePtr);
                // OR,merge with its neighbor.
                else if (leftBro != NULL) {
                    // Merge with left-neighbor
                    merge_children(root, i - 1, leftBro, prePtr);
                    prePtr = leftBro;
                } else // Merge with right-neighbor
                    merge_children(root, i, prePtr, nexPtr);
            }
            /*Now prePtr at least have d keys,just recursively delete X in
             * prePtr*/
            BTreeDeleteNoNone(X, prePtr);
        }
    }
}
/*Get T's left-max key*/
static int BTreeGetLeftMax(node_t *T) {
    if (0 == T->leaf) {
        return BTreeGetLeftMax(T->child_array[T->key_index]);
    } else {
        return T->key_array[T->key_index - 1];
    }
}
/*Get T's right-min key*/
static int BTreeGetRightMin(node_t *T) {
    if (0 == T->leaf) {
        return BTreeGetRightMin(T->child_array[0]);
    } else {
        return T->key_array[0];
    }
}
/* The BTreeDelete operation delete X from T up-to-down and no-backtrack.
** Before delete,check if it's necessary to merge the root and its children
** to reduce the tree's height.Execute BTreeDeleteNoNone to recursively delete
*/
node_t *delete (int key, btree_t *b) {
    if (!b->lock) {
        // if the root of T only have 1 key and both of T's two child have d-1
        // key,then merge the children and the root. Guarantee not need to
        // backtrack.
        if (b->root->key_index == 1) {
            node_t *child1 = b->root->child_array[0];
            node_t *child2 = b->root->child_array[1];
            if ((!child1) && (!child2)) {
                if ((NODE_ORDER - 1 == child1->key_index) &&
                    (NODE_ORDER - 1 == child2->key_index)) {
                    // Merge the children and set child1 to the new root.
                    merge_children(b->root, 0, child1, child2);
                    free(b->root);
                    BTreeDeleteNoNone(key, child1);
                    return child1;
                }
            }
        }
        BTreeDeleteNoNone(key, b->root);
    } else {
        printf("Tree is locked\n");
    }
    return b->root;
}
void tree_unlock(btree_t *r) { r->lock = FALSE; }
bool tree_lock(btree_t *r) {
    if (r->lock) {
        return FALSE;
    }
    r->lock = TRUE;
    return TRUE;
}
//---------------------------------TEST APP
//------------------------------------------
void console(btree_t *b) {
    int number;
    char name[256];
    printf("BTree> ");
    scanf("%s", name);

    if (!strcmp("add", name)) {
        scanf("%d", &number);
        if (number) {
            b->root = insert(number, b);
        }
        printf("Insert %d\n", number);
    } else if (!strcmp("del", name)) {
        scanf("%d", &number);
        if (number) {
            b->root = delete (number, b);
        }
        printf("Delete %d\n", number);
    } else if (!strcmp("search", name)) {
        scanf("%d", &number);
        if (number) {
            result_t *rs = search(number, b->root);
            if (rs->found) {
                printf("Found\n");
                print_node(rs->node_pointer);
            } else {
                printf("Not found\n");
            }
        }
    } else if (!strcmp("tree", name)) {
        printf("  Order: %d\n", b->order);
        printf("   Lock: ");
        if (b->lock) {
            printf("TRUE\n");
        } else {
            printf("FALSE\n");
        }
        print_node(b->root);
    } else if (!strcmp("lock", name)) {
        tree_lock(b);
    } else if (!strcmp("unlock", name)) {
        tree_unlock(b);
    } else if (!strcmp("exit", name)) {
        exit(0);
    } else if (!strcmp("quit", name)) {
        exit(0);
    } else {
        printf("Unknown [%s]\n", name);
    }
    return;
}
int main(int argc, char *argv[]) {
    int test[] = {1,  -11, 12, 13, 15, 16, 17, 18, 19, 20, 25, 28, 29, 31,
                  35, 36,  39, 41, 42, 45, 55, 58, 59, 61, 67, 71, 73, 74,
                  76, 80,  81, 82, 83, 88, 89, 99, 83, 91, 93, 94, 95, 98};
    int test2[] = {-23, -234, -24, -3,   -38, -82, -49, -72, -84,  -27, -22,
                   -35, -9,   -29, -374, -84, -24, -92, -83, -372, -756};
    int todelete[] = {15, 19};
    btree_t *main = create_btree();
    int i;
    for (i = 0; i < sizeof(test) / sizeof(int); i++) {
        main->root = insert(test[i], main);
    }
    for (i = 0; i < sizeof(test2) / sizeof(int); i++) {
        main->root = insert(test2[i], main);
    }
    for (i = 0; i < sizeof(todelete) / sizeof(int); i++) {
        main->root = delete (todelete[i], main);
    }
    // Run console for easy testing
    for (;;) {
        console(main);
    }
    return 0;
}
