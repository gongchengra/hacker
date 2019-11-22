#include <stdio.h>
#define ALLOCSIZE 1000000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
            allocp += n;
            return allocp - n;
        } else
        return 0;
}

void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}

int main()
{
    char *p = alloc(10);
    *p++ = 'H';
    *p++ = 'e';
    *p++ = 'l';
    *p++ = 'l';
    *p++ = 'o';
    *p++ = '\0';
    p -= 6;
    printf("%s\n", p);
    afree(p);
    printf("%s\n", p);
    p = alloc(10001);
    printf("%s\n", p);
    return 0;
}
