#include <stdio.h>
#include <string.h>
int main() {
    int i = 0;
    char *p[] = {"DOG", "CAT", "COMPUTER", "MICROPROCESSOR", "FISH"};
    for (i = 0; i < 5; ++i)
        printf("%s ", *(p + i));
    printf("\nstrlen of the third string is %lu", strlen(*(p+2)));
    printf("\n");
    printf("the second character of the third string is %c", (*(p+2))[1]);
    printf("\n");
    return 0;
}
