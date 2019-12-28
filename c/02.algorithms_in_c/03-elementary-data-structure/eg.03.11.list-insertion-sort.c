#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct node *link;
struct node {
    int item;
    struct node *next;
};
void print_list(link t)
{
  while (t != NULL)
    {
      printf("%d ", t->item);
      t = t->next;
    }
  printf("\n");
}
int main(int argc, char *argv[]) {
    int i, N = atoi(argv[1]);
    struct node heada, headb;
    link t, u, x, a = &heada, b = &headb;
    srand(time(NULL));
    for (i = 0, t = a; i < N; i++) {
        t->next = malloc(sizeof *t);
        t = t->next;
        t->next = NULL;
        t->item = rand() % 1000;
    }
    print_list(a->next);
    for (t = a->next; t != NULL; t = u) {
        u = t->next;
        for (x = b; x->next != NULL; x = x->next) {
            if (x->next->item > t->item)
                break;
        }
        t->next = x->next;
        x->next = t;
    }
    print_list(b->next);
    return 0;
}
