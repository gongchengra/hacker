/***********************************************
  I wrote a version that does not depend of any
  maximum lenght of input lines
  -- TheSunShadow
 ***********************************************/

#include <stdio.h>

/* We are getting pieces of lines of arbitrary length
   without the need of getting the full line at once. */
#define MAXLINE 10

int getlines(char s[], int lim);

main(void)
{
    char line[MAXLINE];
    int i, j, k, len, max = 0;

    while((len = getlines(line, MAXLINE)) > 0){

        /* There are two kind of pieces of lines, whether they
           are at the end of the line or not. */

        if(line[len - 1] != '\n') {       // This is not an end of line,
            printf("%s", line);     // then write the input as is.
        } else {                   // This is an end of line.
            j = 0;

            /* Count the number of spaces or tabs at the end. */
            while((line[len - 2 - j] == ' ') || (line[len - 2 - j] == '\t'))
                ++j;

            /* Write the input without the unwanted characters. */
            if(j < len - 1)
                for(k = 0; k < (len - 1 - j); ++k)
                    printf("%c", line[k]);

            printf("\n");           // This is to recover the right
            // format at the end of line.
        }
    }
}

int getlines(char s[], int lim)
{
    int c, i;

    for(i = 0; i < lim - 1 && ((c = getchar()) != EOF && c != '\n'); ++i)
        s[i] = c;

    if(c == '\n'){
        s[i] = c;
        s[++i] = '\0';
    }

    else if(c == EOF && i > 0){
        s[i] = '\n';
        s[++i] = '\0';
    }

    return i;
}
