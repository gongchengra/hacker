#include <stdio.h>

struct {
    unsigned int is_keyword : 1;
    unsigned int is_extern : 1;
    unsigned int is_static : 1;
    unsigned int is_private : 1;
} flags;
enum { KEYWORD = 01, EXTERNAL = 02, STATIC = 04 };
int main(int argc, char *argv[]){
    flags.is_extern = flags.is_static = 1;
    printf("%d\n", flags.is_extern);
    printf("%lu\n", sizeof(flags));
    printf("%lu\n", sizeof(int));
    printf("%lu\n", sizeof(char));
    int flag = 0;
    flag |= EXTERNAL | STATIC; // turn on
    printf("%d\n", flag);
    flag &= ~(EXTERNAL|STATIC); //turn off
    printf("%d\n", flag);
}
