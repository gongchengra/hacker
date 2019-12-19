#include <stdio.h>
int main(void)
{
    int i = 10;
    int j = 20;
    int const k = 30; /* k is stored in read only state */
    int *ptr = &i;        /* pointer to integer */
    const int *ptr2const = &i;    /* ptr2const is pointer to constant */
    int const *ptr2intconst = &k;    /* pointer to integer constant. Here k
                                        is of type "const int", and &k is of
                                        type "const int *".  And p is of type
                                        "const int", types are matching no issue */
    int *const constptr2int = &j; /* const pointer to integer */
    const int *const constptr2constint = &i;        /* constant pointer to constant integer */

    printf("*ptr: %d\n", *ptr);
    printf("*ptr2const: %d\n", *ptr2const);
    printf("*ptr2intconst: %d\n", *ptr2intconst);
    printf("*constptr2int: %d\n", *constptr2int);
    printf("*constptr2constint: %d\n", *constptr2constint);

    /* pointer is pointing to another variable */
    ptr = &j;
    printf("*ptr: %d\n", *ptr);
    /* we can change value stored by pointer */
    *ptr = 100;
    printf("*ptr: %d\n", *ptr);
    /* warning: assignment discards 'const' qualifier from pointer target type */
    /*    ptr = &k;*/
    /*    printf("*ptr: %d\n", *ptr);*/

    ptr2const = &j;
    printf("*ptr2const: %d\n", *ptr2const);
    /* error: object pointed cannot be modified using the pointer ptr */
    /*    *ptr2const = 100;*/
    /*    printf("*ptr2const: %d\n", *ptr2const);*/

    ptr2intconst = &j; /* valid. We call it as up qualification. In
                          C/C++, the type of "int *" is allowed to up
                          qualify to the type "const int *". The type of
                          &j is "int *" and is implicitly up qualified by
                          the compiler to "cons tint *" */
    printf("*ptr2intconst: %d\n", *ptr2intconst);
    /*error: assignment of read-only location '*ptr2intconst'*/
    /*    *ptr2intconst = 100;*/
    /*    printf("*ptr2intconst: %d\n", *ptr2intconst);*/

    /*error: assignment of read-only variable 'constptr2int'*/
    /*    constptr2int = &j;*/
    /*    printf("*constptr2int: %d\n", *constptr2int);*/
    *constptr2int = 100;
    printf("*constptr2int: %d\n", *constptr2int);

    /*error: assignment of read-only variable 'constptr2constint'*/
    /*    constptr2constint = &j;*/
    /*    printf("*constptr2constint: %d\n", *constptr2constint);*/
    /*error: assignment of read-only variable 'constptr2constint'*/
    /*    *constptr2constint = 100;*/
    /*    printf("*constptr2constint: %d\n", *constptr2constint);*/

    return 0;
}
