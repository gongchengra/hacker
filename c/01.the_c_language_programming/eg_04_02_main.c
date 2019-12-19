#include <stdio.h>
#define MAXLINE 100
/* rudimentary calculator */
int main()
{
    double sum, atof(char []);
    char line[MAXLINE];
    int getlinekr(char line[], int max);
    sum = 0;
    while (getlinekr(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));
    return 0;
}
