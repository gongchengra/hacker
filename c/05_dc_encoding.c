#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 1000
#define RESULT_LEN 3000
#define DC_BASE 256
int main()
{
    int i,j;
    char flag = 0;
    char string[MAX_LEN];
    int result[RESULT_LEN] = {0};

    fflush(stdin);
    printf("Enter string to encode(Less than 1000 characters):\n");
    fgets(string, sizeof(string), stdin);

    for (i = 0;i < MAX_LEN && string[i] != '\0';i++) {
        for (j = RESULT_LEN-1,flag=0;j >= 0;j--) {
            if (result[j] != 0) flag = 1;
            if (flag == 1) result[j] = result[j] * DC_BASE;
        }
        result[0] = result[0] + string[i];
        for (j = 0;j < RESULT_LEN-1;j++) {
            if (result[j] > 9) {
                result[j+1] = result[j+1] + (result[j] / 10);
                result[j] = result[j] % 10;
            }
        }
    }

    for (j = RESULT_LEN-1,flag=0;j >= 0;j--) {
        if (result[j] != 0) flag = 1;
        if (flag == 1) printf("%d", result[j]);
    }
    printf("\n");

    return 0;
}
