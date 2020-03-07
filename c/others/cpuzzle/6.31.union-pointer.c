#include <stdio.h>
union data {
    int a;
    int b;
} ab;
union data Give(union data a) {
    a.a = 78;
    return a;
}
void GiveIt(union data *p) { p->b = 7887; }
int main() {
    ab = Give(ab);
    printf("%d %d\n",ab.a, ab.b);
    GiveIt(&ab);
    printf("%d %d\n",ab.a, ab.b);
    return 0;
}
