#include <stdio.h>
#include <stdlib.h>
int main() {
    int day, month, year;
    char monthname[20];
    /*    scanf("%d %s %d", &day, monthname, &year);*/
    /*    printf("%d, %s, %d", day, monthname, year);*/
    FILE *stream = stdin;
    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, stream) > 0) {
        if (sscanf(line, "%d %s %d", &day, monthname, &year) == 3)
            printf("valid: %s\n", line); /* 25 Dec 1988 form */
        else if (sscanf(line, "%d/%d/%d", &month, &day, &year) == 3)
            printf("valid: %s\n", line); /* mm/dd/yy form */
        else
            printf("invalid: %s\n", line); /* invalid form */
    }
    /*    double sum, v;*/
    /*    sum = 0;*/
    /*    while (scanf("%lf", &v) == 1)*/
    /*        printf("\t%.2lf\n", sum += v);*/
    return 0;
}
