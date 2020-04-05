#include <errno.h>
#include <stdio.h>
#include <string.h>
extern int errno;
int main() {
    FILE *pf;
    if ((pf = fopen("unexist.txt", "rb")) == NULL) {
        int errnum = errno;
        fprintf(stderr, "Value of errno: %d\n", errno);
        perror("Error printed by perror");
        fprintf(stderr, "Error opening file: %s\n", strerror(errnum));
    } else {
        fclose(pf);
    }
    return 0;
}
