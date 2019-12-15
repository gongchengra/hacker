#include <stdio.h>
#define tokenpaster(n) printf("token" #n " = %d\n", token##n)
int main(void) {
    int token34 = 40;
    int token35 = 50;
    tokenpaster(34);
    tokenpaster(35);
    return 0;
}
