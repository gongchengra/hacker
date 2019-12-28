#include "item.h"
#include "stack.h"
#include <stdlib.h>
typedef struct STACKnode *link;
struct STACKnode {
    Item item;
    link next;
};
static link head;
link new (Item item, link next) {
    link x = malloc(sizeof *x);
    x->item = item;
    x->next = next;
    return x;
}
void STACKinit(int maxn) { head = NULL; }
int STACKempty(void) { return head == NULL; }
void STACKpush(Item item) { head = new (item, head); }
Item STACKpop() {
    Item item = head->item;
    link t = head->next;
    free(head);
    head = t;
    return item;
}
