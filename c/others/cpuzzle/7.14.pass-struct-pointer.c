#include <stdio.h>
struct pen {
    int i;
    double j;
};
void count(struct pen *);
int main() {
    static struct pen d = {5, 8.25};
    count(&d);
}
void count(struct pen *p) {
    double x;
    x = p->i * p->j;
    printf("x=%f\n", x);
}
