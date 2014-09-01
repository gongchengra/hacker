#include <stdio.h>
/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high)/2;
        printf("mid = %d\n",mid);
        if (x < v[mid]){
            high = mid - 1;
            printf("high = %d\n",high);
        }
        else if (x > v[mid]){
            low = mid + 1;
            printf("low = %d\n",low);
        }
        else
            /* found match */
            return mid;
    }
    return -1;
    /* no match */
}
int main()
{
    int v[10]={1,3,5,7,9,10,11,15,18,20};
    int x=7;
    int n=10;
    int l;
    l =binsearch(x,v,n);
/*    printf("The location of %d is %d \n",7,binsearch(7,v,10));*/
    printf("The location of %d is %d \n",x,l);
}
