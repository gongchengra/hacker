#include <stdio.h>
int main() {
    char *p, a = 'A', b = 'B';
    p = &a;
    printf("%p, %c\n", p, *p);
	p--;
	printf("%p, %c\n", p, *p);
    return 0;
}
