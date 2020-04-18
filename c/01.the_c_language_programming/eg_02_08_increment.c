#include <stdio.h>
/* squeeze: delete all c from s */
void squeeze(char s[], int c) {
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}
/* strcat: concatenate t to end of s; s must be big enough */
void strcatkr(char s[], char t[]) {
    int i, j;
    i = j = 0;
    while (s[i] != '\0') /* find end of s */
        i++;
    while ((s[i++] = t[j++]) != '\0') /* copy t */
        ;
}
int main() {
    int c = 'c';
    char test_string1[100] = "abcdef cat dog cc drush";
    char test_string2[] = "I love Yingjuan!";
    /*    printf("%d\n",atoi("8769123"));*/
    strcatkr(test_string1, test_string2);
    printf("%s\n", test_string1);
    squeeze(test_string1, c);
    printf("%s\n", test_string1);
}
