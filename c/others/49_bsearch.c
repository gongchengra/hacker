#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct mi {
    int nr;
    char *name;
} months[] = {{1, "jan"}, {2, "feb"},  {3, "mar"},  {4, "apr"},
              {5, "may"}, {6, "jun"},  {7, "jul"},  {8, "aug"},
              {9, "sep"}, {10, "oct"}, {11, "nov"}, {12, "dec"}};
#define nr_of_months (sizeof(months) / sizeof(months[0]))
static int compmi(const void *m1, const void *m2) {
    /*    struct mi *mi1 = (struct mi *)m1;*/
    /*    struct mi *mi2 = (struct mi *)m2;*/
    /*    return strcmp(mi1->name, mi2->name);*/
    return strcmp((*(struct mi *)m1).name, (*(struct mi *)m2).name);
}
int cmp(const void *m1, const void *m2) {
    return ((*(struct mi *)m1).nr - (*(struct mi *)m2).nr);
}
bool isNumber(char argv[]) {
    for (int i = 0; argv[i] != 0; i++) {
        if (!isdigit(argv[i])) {
            return false;
        }
    }
    return true;
}
void lowerArgv(char argv[]) {
    for (int i=0; argv[i] != 0;i++){
        argv[i] = tolower(argv[i]);
    }
}
int main(int argc, char **argv) {
    int i;
    if (argc < 2) {
        qsort(months, nr_of_months, sizeof(struct mi), compmi);
        for (i = 0; i < nr_of_months; i++) {
            printf("%s: month #%d\n", months[i].name, months[i].nr);
        }
        qsort(months, nr_of_months, sizeof(struct mi), cmp);
        for (i = 0; i < nr_of_months; i++) {
            printf("%s: month #%d\n", months[i].name, months[i].nr);
        }
    } else {
        for (i = 1; i < argc; i++) {
            struct mi key, *res;
            if (isNumber(argv[i])) {
                qsort(months, nr_of_months, sizeof(struct mi), cmp);
                int n = atoi(argv[i]);
                if (n < 1 || n > 12) {
                    printf("%s: unknown month\n", argv[i]);
                } else {
                    key.nr = n;
                    res = bsearch(&key, months, nr_of_months, sizeof(struct mi),
                                  cmp);
                    printf("the #%d month is %s\n", res->nr, res->name);
                }
            } else {
                qsort(months, nr_of_months, sizeof(struct mi), compmi);
                lowerArgv(argv[i]);
                key.name = argv[i];
                res = bsearch(&key, months, nr_of_months, sizeof(struct mi),
                              compmi);
                if (res == NULL)
                    printf("%s: unknown month\n", argv[i]);
                else
                    printf("%s: month #%d\n", res->name, res->nr);
            }
        }
    }
    exit(EXIT_SUCCESS);
}
