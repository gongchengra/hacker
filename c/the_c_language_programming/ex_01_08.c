#include <stdio.h>
main()
{
    int c, nl = 0, ns = 0, nt = 0;

    while((c = getchar()) != EOF) {
        if(c == '\n') {
            ++nl;
        }
        if(c == '\t') {
            ++nt;
        }
        if(c == ' ') {
            ++ns;
        }
    }

    printf("the number of spaces is %d\n", ns);
    printf("the number of tabs is %d\n", nt);
    printf("the number of lines is %d\n", nl);

}
