/* K&R2: 1.9, Character Arrays, exercise 1.16

STATEMENT:
revise the main routine of the longest-line programme
so it will correctly print the length of the arbitrarily
long input lines including as much of th possible text.
*/

#include<stdio.h>

#define MAXLINE 1000

int getlines(char [], int max);
void copy(char from[], char to[]);

int main()
{
    int len = 0; /* current line length */
    char line[MAXLINE]; /* current input line */

    while((len = getlines(line, MAXLINE)) > 0)
    {
        printf("LENGTH: %d\n", len);
        printf("LINE-CONTENTS:  %s\n", line);
    }

    return 0;
}


int getlines(char line[], int max)
{
    int i = 0; /* simply an index counter */
    int c = 0; /* variale to store user input */

    for(i = 0; ((c = getchar()) != EOF) && c != '\n' && i < max - 1; ++i)
        line[i] = c;

    if(c == '\n')
        line[i++] = c;

    line[i] = '\0';

    return i;
}
