/********************************************************
I think this is Category 0, but I may be wrong.

I didn't look at any other soutions before I wrote this,
  and I have no idea what similarity it may or may not have
  to other solutions.  I give a statistical summary of word
  lengths, followed by both a horiontal and a vertical
  histograph. The input need not be ended by a newline.
  -- Pilcrow
  ********************************************************/

#include <stdio.h>
#define is__lower(N) ((N) >= 'a' && (N) <= 'z')
#define is__upper(N) ((N) >= 'A' && (N) <= 'Z')
#define is__alpha(N) (is__upper(N) || is__lower(N))
#define OUT__WORD    0
#define IN__WORD     1
#define MAX_WRD_LEN  1000

int main()
{
    int status, longest, most, i, j, k, len;
    char c;
    int word[MAX_WRD_LEN];

    for(i=0;i < MAX_WRD_LEN;i++){word[i] = 0;}  /* clear counts */
    len = 0;
    status = OUT__WORD;

    while((c=getchar())!= EOF) {       /* for each input char */
        if(is__alpha(c)) {             /* if an alphabetic */
            if(status == OUT__WORD) {  /* beginning word? */
                status = IN__WORD;     /* now inside a word */
                ++word[len];           /* bump prev word length's count */
                len = 1;               /* reset to words of length 1 */
            }else {++len;}             /* in a word, bump length of current word */
        }else {                        /* not an alphabetic */
            status = OUT__WORD;        /* now not in a word */
        }
    }
    ++word[len];                       /* bump last word length count */

    longest = 0, most = 0;
    puts("\nSTATISTICS\n");
    for(i=1;i< MAX_WRD_LEN;i++) {
        if(word[i] && i > longest)longest = i;
        if(word[i] > most)most=word[i];
        if(word[i]){printf("%2d words of length %d\n",word[i],i);}
    }
    printf("\ngreatest word length: %d\n",longest);
    printf("most words of a given length: %d\n",most);

    /* horizontal histograph */
    puts("\nHORIONTAL HISTOGRAPH");
    puts("\nword length | graph");
    for(i=1;i <=longest; i++) {
        printf("%11d : ",i);
        for(j=1;j<=word[i];j++) printf("x");
        putchar('\n');
    }

    /* vertical histograph */
    puts("\nVERTICAL HISTOGRAPH");
    puts("\nWd Ct:");
    for(k=most;k>0;k--) {
        printf("%5d:   ",k);
        for(i = 1; i<= longest; i++) {
            if(word[i] < k) printf("    ");
            else printf("x   ");
        }
        putchar('\n');
    }
    printf("      ");
    for(i=1;i<=longest;i++)printf("====");
    printf("\nWd Ln:");
    for(i=1;i<=longest;i++)printf("%4d",i);
    putchar('\n');
    return 0;
}

