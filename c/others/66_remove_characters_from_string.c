#include <ctype.h>
#include <stdio.h>
int main(int argc, char **argv) {
    char line[150];
    printf("Enter a String:");
    fgets(line, sizeof line, stdin);
    for (int i = 0; line[i] != '\0'; ++i) {
        while (!(1 == isalpha(line[i]) || '\0' == line[i])) {
            /*        while (!((line[i] >= 'a' && line[i] <= 'z') || (line[i] >=
             * 'A' && line[i] <= 'Z') || line[i] == '\0')) {*/
            int j;
            for (j = i; line[j] != '\0'; ++j) {
                line[j] = line[j + 1];
            }
            line[j] = '\0';
        }
    }
    puts(line);
}
