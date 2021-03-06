#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include "eg_04_03_calc.h"
#define MAXOP 100 /* max size of operand or operator */
/* reverse Polish calculator */
// 1 2 - 4 5 + * means (1-2)*(4+5) = -9
// run by gcc eg_04_03_*.c -o eg_04_03.exe && ./eg_04_03.exe
int main()
{
    int type;
    double op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}
