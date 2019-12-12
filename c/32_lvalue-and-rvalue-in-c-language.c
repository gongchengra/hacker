#include <stdio.h>
// https://www.geeksforgeeks.org/lvalue-and-rvalue-in-c-language/
// The l-value is one of the following:
//
// The name of the variable of any type i.e, an identifier of integral,
// floating, pointer, structure, or union type. A subscript ([ ]) expression
// that does not evaluate to an array. A unary-indirection (*) expression that
// does not refer to an array An l-value expression in parentheses. A const
// object (a nonmodifiable l-value). The result of indirection through a
// pointer, provided that it isn’t a function pointer. The result of member
// access through pointer(-> or .)
void fun1() {
    // declare a an object of type 'int'
    int a;

    // a is an expression referring to an
    // 'int' object as l-value
    a = 1;

    int b = a; // Ok, as l-value can appear on right

    // Switch the operand around '=' operator
    // Compilation error:
    // as assignment is trying to change the
    // value of assignment operator
    // 9 = a;
}
void fun2() {
    // declare a, b an object of type 'int'
    int a = 1, b;

    // Error, left expression is is not variable(a + 1)
    // a + 1 = b;

    // declare pointer variable 'p', and 'q'
    int *p, *q; // *p, *q are lvalue

    *p = 1; // valid l-value assignment

    // below is invalid - "p + 2" is not an l-value
    // p + 2 = 18;

    // valid - "p + 5" is an r-value, but segment fault.
    q = p + 5;
    printf("%p %p\n", q, p); // 0x7ffee09b2384 0x7ffee09b2370
    printf("%lu\n", (0x7ffeee7ea384-0x7ffeee7ea370)/sizeof(int)); // 20/4 = 5

    // Below is valid - dereferencing pointer
    // expression gives an l-value
    // *(p + 2) = 18;

    p = &b;

    int arr[20]; // arr[12] is an lvalue; equivalent
                 // to *(arr+12)
                 // Note: arr itself is also an lvalue

    struct S {
        int m;
    };

    struct S obj; // obj and obj.m are lvalues

    // ptr-> is an lvalue; equivalent to (*ptr).m
    // Note: ptr and *ptr are also lvalues
    struct S *ptr = &obj;
}
int main() {
    fun1();
    fun2();
}
