#include <stdio.h>
/* shellsort: sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n)
{
    int gap, i, j, temp,k;
    for (gap = n/2; gap > 0; gap /= 2){
        printf("gap=%d\n",gap);
        for (i = gap; i < n; i++){
            printf("i=%d\n",i);
            for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) {
                printf("j=%d\n",j);
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
                for(k= 0; k< n;k ++){
                    printf("%d\t",v[k]);
                }
                printf("\n");
            }
        }
    }
}
int main()
{
/*    int a[] = {1,2,3,4,5,6,7,8,9,10};*/
/*    int a[] = {29, 56, 36, 123, 32, 21, 9, 20, 35, 89};*/
    int a[] = {10,9,8,7,6,5,4,3,2,1,0};
    int i = 0;
    shellsort(a,sizeof(a)/sizeof(int));
    for(i= 0; i< sizeof(a)/sizeof(int);i ++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}
