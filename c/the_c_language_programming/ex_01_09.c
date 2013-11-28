#include <stdio.h>
main()
{
    int c, ns = 0;

    while((c = getchar()) != EOF) {
        if(c == ' ') {
            if(0 == ns) {
                ns = 1;
                putchar(c);
            }
        } else {
            ns = 0;
            putchar(c);
        }
    }

}
