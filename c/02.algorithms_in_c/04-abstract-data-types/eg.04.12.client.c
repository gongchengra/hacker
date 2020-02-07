#include "item.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {
    int i, n = atoi(argv[1]);
    STACKinit(n);
    for (i = 1; i <= n; i++) {
        STACKpush((i % 2 == 1) ? 2 * i : i);
        /*        STACKpush(i);*/
    }
    for (i = 0; i < n; i++) {
        printf("%d \n", STACKpop());
    }
    return 0;
}
