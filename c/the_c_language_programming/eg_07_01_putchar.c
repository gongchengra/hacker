#include <stdio.h>
#include <ctype.h>
int main() /* lower: convert input to lower case*/
{
    int c;
    while ((c = getchar()) != EOF) putchar(tolower(c));
    return 0;
}
