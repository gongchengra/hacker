/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : pi.c

* Author : gongchengra@gmail.com

* Purpose : Calculate pi
*
* pi=16actan(1/5)-4actan(1/239)
*
* actan（x）=x-x**3/3+x**5/5-x**7/7+....
*
* pi=3.2-4/239-1/3*(3.2/25-4/239**3)+1/5*(3.2/25**2-4/239**5)+...
*
* use d5 to store the 16/5, 16/5**3, 16/5**5, ...
*
* use d239 to store the divide of 4/239, 4/239**3, 4/239**5, ...
*
* use m239 to store the modulo of 4/239, 4/239**3, 4/239**5, ...
*
* use dpi to store the divide of (16/5-4/239), (16/5-4/239)/3, (16/5-4/239)/5, ...
*
* use mpi to store the modulo of (16/5-4/239), (16/5-4/239)/3, (16/5-4/239)/5, ...
*
* use pi to store the final result

* Creation Date : 2015-01-07

* Last Modified :

_._._._._._._._._._._._._._._._._._._._._.*/

#include <stdio.h>
#define NUMBER 10000
int main()
{
    int i,j,k,tmp;
    int flag=1;
    int d5[NUMBER]={0};
    int t5[NUMBER]={0};
    int d239[NUMBER]={0};
    int t239[NUMBER]={0};
    int m239[NUMBER]={0};
    int pi[NUMBER]={0};

    //  16/5=3.2;
    t5[0]=3;
    t5[1]=2;
    t239[0]=4;
    for(j=1;j<NUMBER;j++)
    {
        d239[j]=t239[j];
        tmp=d239[j-1]*10+d239[j];
        t239[j]=tmp/239;
        m239[j]=tmp%239;
    }

    for(j=0;j<NUMBER;j++)
    {
        pi[j]+=t5[j];
    }
    for(j=NUMBER-1;j>=0;j--)
    {

    }

    for(i=1;i<NUMBER/4;i++)
    {

    }

}
