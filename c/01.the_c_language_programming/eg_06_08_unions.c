#include <stdio.h>
int main(int argc, char *argv[]) {
    union u_tag {
        int ival;
        float fval;
        char *sval;
    } u;
    u.ival = 10;
    printf("%d\n", u.ival);
    u.fval = 20.0;
    printf("%f\n", u.fval);
    printf("%d\n", u.ival); // 1101004800 is the memory value for 20.0
    u.sval = "test union";
    printf("%d\n", u.ival); // doesn't make sense
    printf("%f\n", u.fval); // doesn't make sense
    printf("%s\n", u.sval);
    u.ival = (int)10.1;
    printf("%d\n", u.ival);
}
