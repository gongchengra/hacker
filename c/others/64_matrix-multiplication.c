#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#define SIZE 9
void display(int matrix[SIZE][SIZE], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%7d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void fdisplay(FILE *fp, int matrix[SIZE][SIZE], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            fprintf(fp, "%7d", matrix[i][j]);
        }
        fprintf(fp, "\n");
    }
}
void input(int matrix[SIZE][SIZE], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}
void multiply(int first[SIZE][SIZE], int second[SIZE][SIZE],
              int result[SIZE][SIZE], int r1, int c1, int r2, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}
void writeTxt(int first[SIZE][SIZE], int second[SIZE][SIZE],
              int result[SIZE][SIZE], int r1, int c1, int r2, int c2) {
    FILE *fp;
    fp = fopen("64_matrix-multiplication.txt", "w");
    fprintf(fp, "First matrix:\n");
    fdisplay(fp, first, r1, c1);
    fprintf(fp, "Second matrix:\n");
    fdisplay(fp, second, r2, c2);
    fprintf(fp, "Result matrix:\n");
    fdisplay(fp, result, r1, c2);
    fclose(fp);
}
void readTxt(int first[SIZE][SIZE], int second[SIZE][SIZE], int *r1, int *c1,
             int *r2, int *c2) {
    FILE *fp;
    char buff[255];
    fp = fopen("64_matrix-multiplication.txt", "r");
    int flag1 = 0, flag2 = 0;
    int val;
    while (fgets(buff, sizeof(buff), fp) != NULL) {
        if (strncmp(buff, "First matrix:\n", 6) == 0) {
            flag1 = 1;
            continue;
        }
        if (strncmp(buff, "Second matrix:\n", 6) == 0) {
            flag1 = 0;
            flag2 = 1;
            continue;
        }
        if (strncmp(buff, "Result matrix:\n", 6) == 0) {
            flag2 = 0;
        }
        if (flag1 == 1) {
            for (int i = 0; i < 255; i++) {
                if (buff[i] == '\n') {
                    break;
                } else {
                    *c1 = i / 7 + 1;
                }
            }
            for (int i = 0; i < *c1; i++) {
                sscanf(buff + i * 7, "%7d", &val);
                first[*r1][i] = val;
            }
            *r1 = *r1 + 1;
        }
        if (flag2 == 1) {
            for (int i = 0; i < 255; i++) {
                if (buff[i] == '\n') {
                    break;
                } else {
                    *c2 = i / 7 + 1;
                }
            }
            for (int i = 0; i < *c2; i++) {
                sscanf(buff + i * 7, "%7d", &val);
                second[*r2][i] = val;
            }
            *r2 = *r2 + 1;
        }
    }
    fclose(fp);
}
int main(int argc, char **argv) {
    int first[SIZE][SIZE], second[SIZE][SIZE], result[SIZE][SIZE];
    int i, j, k;
    int r1 = 0, c1 = 0, r2 = 0, c2 = 0;
    FILE *fp;
    if (access("64_matrix-multiplication.txt", R_OK) == 0) {
        readTxt(first, second, &r1, &c1, &r2, &c2);
    } else {
        srand(time(NULL));
        r1 = 1 + rand() % SIZE;
        c1 = r2 = 1 + rand() % SIZE;
        c2 = 1 + rand() % SIZE;
        input(first, r1, c1);
        input(second, r2, c2);
    }
    if (c1 != r2) {
        printf("column number of first matrix not equal to "
               "row number of second matrix, can not calulate.\n");
        return 1;
    }
    multiply(first, second, result, r1, c1, r2, c2);
    printf("First matrix:\n");
    display(first, r1, c1);
    printf("Second matrix:\n");
    display(second, r2, c2);
    printf("Result matrix:\n");
    display(result, r1, c2);
    writeTxt(first, second, result, r1, c1, r2, c2);
    return 0;
}
