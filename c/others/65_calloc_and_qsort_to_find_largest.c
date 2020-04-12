#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int cmp(const void *a, const void *b) {
    return (*(float *)b - *(float *)a) > 0
               ? 1
               : (*(float *)b == *(float *)a) ? 0 : -1;
}
int main(int argc, char **argv) {
    int num;
    float *data;
    if (argc > 1) {
        num = atoi(argv[1]);
    } else {
        printf("Enter total number of elements:");
        scanf("%d", &num);
    }
    data = (float *)calloc(num, sizeof(float));
    if (data == NULL) {
        printf("Unable to assign memory.\n");
        return 1;
    }
    srand(time(NULL));
    for (int i = 0; i < num; i++) {
        *(data + i) = (float)(rand() % 1000) / 100.0;
        /*        if(*data < *(data +i)) {*/
        /*            *data = *(data +i);*/
        /*        }*/
        printf("%4.2f ", *(data + i));
    }
    qsort(data, num, sizeof(float), cmp);
    printf("\n");
    for (int i = 0; i < num; i++) {
        printf("%4.2f ", *(data + i));
    }
    printf("\n");
    printf("The largest element is : %5.2f \n", *data);
    return 0;
}
