#include <stdio.h>
/*void func(struct uda *b);*/
#define INT 1
#define LONG 2
#define FLOAT 3
#define DOUBLE 4
#define STRING 5
struct uda {
    union {
        int uin;
        long ulo;
        float uf;
        double udo;
        char *ust;
    } u;
    int type;
} x;
void func(struct uda *b) {
    switch (b->type) {
    case INT:
        printf("%d\n", b->u.uin);
        break;
    case LONG:
        printf("%ld\n", b->u.ulo);
        break;
    case FLOAT:
        printf("%f\n", b->u.uf);
        break;
    case DOUBLE:
        printf("%lf\n", b->u.udo);
        break;
    case STRING:
        printf("%s\n", b->u.ust);
    }
}
int main() {
    x.type = 1;
    x.u.uin = 123;
    func(&x);
    x.type = 2;
    x.u.ulo = 123456789;
    func(&x);
    x.type = 3;
    x.u.uf = 1.5;
    func(&x);
    x.u.udo = 12.03;
    x.type = 4;
    func(&x);
    x.u.ust = "Go home!";
    x.type = 5;
    func(&x);
}
