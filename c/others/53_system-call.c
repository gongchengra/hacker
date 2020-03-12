#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("test system clear\n");
    char c;
    scanf("%c", &c);
    if(c == 'c' || c == 'C') system("clear");
    else printf("%c", c);
    printf("test system clear\n");
}
