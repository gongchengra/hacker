#include <stdio.h>
/* qsort: sort v[left]...v[right] into increasing order */
void qsort(int v[], int left, int right) {
    int i, last;
    void swap(int v[], int i, int j);
    if (left >= right) /* do nothing if array contains */
                       /* fewer than two elements */
        return;
    swap(v, left, (left + right) / 2); /* move partition elem to v[0] */
    last = left;
    for (i = left + 1; i <= right; i++) /* partition */
        if (v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);
    /* restore partition elem */
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}
/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j) {
    int temp;
    int n;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
    for (n = 0; n < 5; n++) {
        printf("%d ", v[n]);
    }
    printf("\n");
}
int main(void) {
    int values[] = {88, 56, 100, 2, 25};
    int n;

    printf("Before sorting the list is: \n");
    for (n = 0; n < 5; n++) {
        printf("%d ", values[n]);
    }
    printf("\n");
    qsort(values, 0, 4);
    printf("\nAfter sorting the list is: \n");
    for (n = 0; n < 5; n++) {
        printf("%d ", values[n]);
    }
    return 0;
}
