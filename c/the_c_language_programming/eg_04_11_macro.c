#include <stdio.h>
#define dprint(expr) printf(#expr " = %g\n",expr)
int main(void){
    printf("1.0/3 " "= %g\n", 1.0/3);
    dprint(1.0/3);
    return 100;
}
