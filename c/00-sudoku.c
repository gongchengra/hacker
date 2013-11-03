#include <stdio.h>
void print(int a[9][9]) /*格式化输出数独*/
{
    int i,j;
    for(i=0;i<9;i++)
    {for(j=0;j<9;j++)
        printf("%d ",a[i][j]);
        printf("\n");
    }
}
void ini_logo(int logo[10][9][9],int arr[9][9]) /*初始化标志数组*/
{
    int i,j,k,p,r,s,t;
    for(i=0;i<9;++i)
        for(j=0;j<9;++j)
            if(arr[i][j]!=0)
                for(k=1;k<=9;++k)logo[k][i][j]=1;
    for(i=0;i<9;++i)
        for(j=0;j<9;++j)
            if(arr[i][j]!=0)
            {
                p=arr[i][j];
                for(r=0;r<9;++r)
                {
                    logo[p][i][r]=1;
                    logo[p][r][j]=1;
                }
                for(s=(i/3)*3;s<(i/3)*3+3;++s)
                    for(t=(j/3)*3;t<(j/3)*3+3;++t)
                        logo[p][s][t]=1;
            }
}
int add(int arr[9][9],int logo[10][9][9],int m,int n,int k) /*arr[m][n]插入数字，修改arr,logo数组*/
{
    int i,s,p,t;
    arr[m][n]=k;
    for(p=1;p<=9;++p)
        logo[p][m][n]=1;
    for(i=0;i<9;++i)
    {
        logo[k][m][i]=1;
        logo[k][i][n]=1;
    }
    for(s=(m/3)*3;s<(m/3)*3+3;++s)
        for(t=(n/3)*3;t<(n/3)*3+3;++t)
            logo[k][s][t]=1;
}
int check(int logo[10][9][9],int arr[9][9]) /*检测行列和小九宫格*/
{
    int i,j,k,p,q,r,s,t,m,n,tag=0; /*tag标志本轮是否修改*/
    for(k=1;k<=9;++k)
    {
        for(i=0;i<9;++i)
        {
            p=0;q=0;
            for(j=0;j<9;++j)
            {
                if(logo[k][i][j]==0){r=j;p++;} /*检测行*/
                if(logo[k][j][i]==0){s=j;q++;} /*检测列*/
            }
            if(p==1){tag=1;add(arr,logo,i,r,k);}
            if(q==1){tag=1;add(arr,logo,s,i,k);} /*满足一个添加的条件，修改arr,logo数组和标志tag*/
        }
        for(i=0;i<9;i=i+3) /*检测小九宫格*/
            for(j=0;j<9;j=j+3)
            {
                t=0;
                for(m=i;m<i+3;++m)
                    for(n=j;n<j+3;++n)
                        if(logo[k][m][n]==0){q=m;s=n;t++;}
                if(t==1){tag=1;add(arr,logo,q,s,k);}
            }
    }
    return(tag);
}
main()
{
    int arr[9][9]={
        0,0,0,0,0,0,0,0,0,/*数独初始化，其中0表示数字未给出*/
        0,2,3,0,0,0,7,8,0,
        1,0,0,4,0,6,0,0,9,
        4,0,0,0,5,0,0,0,1,
        9,0,0,0,0,0,0,0,6,
        0,6,0,0,0,0,0,9,0,
        0,0,5,0,0,0,8,0,0,
        0,0,0,3,0,1,0,0,0,
        0,0,0,0,9,0,0,0,0
    },
        logo[10][9][9]={0},i,j;
    ini_logo(logo,arr);
    while(check(logo,arr)==1) /*当一轮没有检测出，即结束*/
    {}
    print(arr);
} 
