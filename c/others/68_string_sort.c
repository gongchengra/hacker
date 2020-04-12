#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a, const void *b) {return -strcmp((char *)a, (char *)b);}
int main(int argc, char **argv){
    char str[5][50];
    printf("Enter 5 sentence:");
    for(int i=0;i<5;i++){
        fgets(str[i], sizeof(str[i]), stdin);
    }
    qsort(str, 5, 50, cmp);
    for(int i=0;i<5;i++){
        printf("%s", str[i]);
    }
}
