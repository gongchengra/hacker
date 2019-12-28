#include "item.h"
#include "stack.h"
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
    char *a = argv[1];
    int i, n = strlen(a);
    STACKinit(n);
    for (i = 0; i < n; i++) {
        if (a[i] == '+')
            STACKpush(STACKpop() + STACKpop());
        if (a[i] == '*')
            STACKpush(STACKpop() * STACKpop());
        if ((a[i] >= '0') && (a[i] <= '9'))
            STACKpush(0);
        while ((a[i] >= '0') && (a[i] <= '9'))
            STACKpush(10 * STACKpop() + (a[i++] - '0'));
    }
    printf("%d \n", STACKpop());
    return 0;
}
