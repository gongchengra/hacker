/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : 77_macro_foreach.c
* Author : gongchengra@gmail.com
* Purpose :
* Creation Date : 2020-04-16
* Last Modified :
_._._._._._._._._._._._._._._._._._._._._.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 10
#define max 1000
typedef struct ListNode {
    struct ListNode *next;
    struct ListNode *prev;
    void *value;
} ListNode;
typedef struct List {
    int count;
    ListNode *first;
    ListNode *last;
} List;
#define LIST_FOREACH(curr, list)                                               \
    ListNode *curr = list->first;                                              \
    for (ListNode *_node = list->first; _node != NULL;                         \
         curr = _node = _node->next)
void newNode(List *lst) {
    ListNode n;
    n.value = (void *)(size_t)(rand() % max);
    lst->first = &n;
    lst->count++;
}
int main(int argc, char **argv) {
    List *lst;
    srand(time(NULL));
    lst = malloc(size * sizeof(lst));
    if (lst == NULL) {
        printf("No memery!\n");
        return 1;
    }
    ListNode n, head;
    head.value = (void *)(size_t)(rand() % max);
    n.prev = &head;
    n.next = NULL;
    n.value = head.value + 1;
    head.next = &n;
    lst->first = &head;
    for (int i = 0; i < size; i++) {
        ListNode t;
        t.prev = &n;
        t.next = NULL;
        t.value = (void *)(size_t)(rand() % max);
        printf("%5d", (int)t.value);
        n = t;
    }
    printf("\n");
    LIST_FOREACH(curr, lst) { printf("%d\n", (int)curr->value); }
}
