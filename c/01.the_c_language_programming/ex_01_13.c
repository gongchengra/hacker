#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
#define maxlen 10 /* outside a word */

int main()
{
    int c, nl, nw, state, i, flag, maxval;
    state = OUT;
    maxval = 0;
    int ndigit[maxlen];
    for (i = 0; i < maxlen; ++i)
        ndigit[i] = 0;
    nl = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t'){
            state = OUT;
            if(flag != state){
                ndigit[nl]++;
                if(ndigit[nl] > maxval) {
                    maxval = ndigit[nl];
                }
            }
        } else {
           state = IN;
           if(flag != state) {
               nl = 0;
           } else {
               nl++;
           }
        }
        flag = state;
    }
    for (i = 0; i < maxlen; ++i) {
        printf(" %d  ", i+1);
        for(nw = 0; nw < ndigit[i]; nw++) {
            printf("*");
        }
        printf("\n");
    }

    printf("\n");
    printf("\n");
    for (i = maxval; i >= 1; i--) {
        printf("%4d", i);
        for (nw = 0; nw < maxlen; nw++) {
            if(ndigit[nw] >= i) {
                printf("  *");
            } else
            {
                printf("   ");
            }
        }
        printf("\n");
    }
    printf("idx:");
    for (i = 1; i < maxlen; i++)
    {
        printf("%3d", i);
    }
    printf("\n");
    return 0;
}
