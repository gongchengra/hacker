#include <stdio.h>
/* count frequency of characters */
main()
{
    int c, i, nwhite, nother;
    int ndigit[10];
    int nlower[26];
    int nupper[26];

    //initialize
    nwhite = nother = 0;
    for (i = 0; i < 26; ++i) {
        if(i < 10) {
            ndigit[i] = 0;
        }
        nlower[i] = 0;
        nupper[i] = 0;
    }

    //catch input and count frequency
    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9')
            ++ndigit[c-'0'];
        else if (c >= 'a' && c <= 'z')
            ++nlower[c-'a'];
        else if (c >= 'A' && c <= 'Z')
            ++nupper[c-'A'];
        else if (c == ' ')
            ++nwhite;
        else
            ++nother;
    }

    //count the max number of all characters
    int max_cnt = 0;
    for (i = 0; i < 26; ++i) {
        if(i < 10) {
            max_cnt = max_cnt > ndigit[i] ? max_cnt : ndigit[i];
        }
        max_cnt = max_cnt > nlower[i] ? max_cnt : nlower[i];
        max_cnt = max_cnt > nupper[i] ? max_cnt : nupper[i];
    }
    max_cnt = max_cnt > nwhite ? max_cnt : nwhite;
    max_cnt = max_cnt > nother ? max_cnt : nother;

    //output results in histogram
    int ntmp;
    for (i = max_cnt; i >= 1; i--) {
        printf("%4d", i);
        for (ntmp = 0; ntmp < 10; ntmp++) {
            if(ndigit[ntmp] >= i) {
                printf("  *");
            } else
            {
                printf("   ");
            }
        }
        for (ntmp = 0; ntmp < 26; ntmp++) {
            if(nlower[ntmp] >= i) {
                printf("  *");
            } else
            {
                printf("   ");
            }
        }
        for (ntmp = 0; ntmp < 26; ntmp++) {
            if(nupper[ntmp] >= i) {
                printf("  *");
            } else
            {
                printf("   ");
            }
        }
        if(nwhite >= i) {
            printf("  *");
        } else
        {
            printf("   ");
        }
        if(nother >= i) {
            printf("  *");
        } else
        {
            printf("   ");
        }
        printf("\n");
    }
    printf("idx:");
    for (i = 0; i < 10; i++)
    {
        printf("%3d", i);
    }
    for (i = 0; i < 26; i++)
    {
        putchar(' ');
        putchar(' ');
        putchar('a'+i);
    }
    for (i = 0; i < 26; i++)
    {
        putchar(' ');
        putchar(' ');
        putchar('A'+i);
    }
    printf("%3s","spa");
    printf("%3s","oth");
    printf("\n");
    return 1;
}
