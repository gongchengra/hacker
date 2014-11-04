#include <stdio.h>
int main(void)
{
    /* f: function returning pointer to int */
    int *f();

    /* pf: pointer to function returning int */
    int (*pf)();

    /* argv: pointer to char */
    char **argv;

    /* daytab: pointer to array[13] of int*/
    int (*daytab)[13];

    /* daytab: array[13] of pointer to int*/
    int *daytab[13];

    /* comp: function returning pointer to void*/
    void *comp();

    /* comp: pointer to function returning void*/
    void (*comp)();

    /* x: function returning pointer to array[] of pointer to function returning char*/
    char (*(*x())[])();

    /* x: array[3] of pointer to function returning pointer to array[5] of char*/
    char (*(*x[3])())[5];

    return 0;

}
