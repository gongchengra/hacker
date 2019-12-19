#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long LL;

int a[25];
LL dp[25][3];
//dp[i][0] len <= i && 包含 49 的个数
//dp[i][1] len = i && 首位是 9 && 不包含 49 的个数
//dp[i][2] len <= i && 不包含 49 的个数
void init()
{
    memset(dp, 0, sizeof(dp));
    dp[0][2] = 1;
    for(int i = 1; i < 22; i++)
    {
        //转移方程
        dp[i][0] = 10 * dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][2];
        dp[i][2] = 10 * dp[i-1][2] - dp[i-1][1];
    }
}
LL sol(LL x)
{
    int w = 0;
    x++;                //答案没有算自身，统计的是(1, n)开区间，可以变为统计(1,n+1); 或者返回答案时特判+1。
    while(x)
    {
        a[++w] = x % 10;
        x /= 10;
    }
    a[w+1] = 0;

    LL ans = 0;
    int flag = false;                   //flag 表示前几位中是否存在49

    for(int i = w; i > 0; i--)
    {
        ans += a[i] * dp[i-1][0];
        if(flag)
        //前几位存在49时 剩余位全都符合 ans += a[i]*1e(i-1)
        //因为1e(i-1)可以拆成dp[i-1][0]+dp[i-1][2], 只需再加上dp[i-1][2]
            ans += a[i] * dp[i-1][2];
        else
        //不存在49时 0~a[i]-1已考虑 即为a[i]*dp[i-1][0]，只需再考虑a[i]的情况
        {
            if(a[i] > 4)      //a[i]>4时 i位可以为4和i-1位为9且不含49的情况组合 一共dp[i-1][1]个
                ans += dp[i-1][1];
            if(a[i+1] == 4 && a[i] == 9)  //出现49 标记
                flag = true;
        }
    }
    //if(flag) ans++;
    return ans;
}
int main(int argc, char const *argv[])
{
    init();
    int t;
    scanf("%d", &t);
    while(t--)
    {
        LL n;
        scanf("%lld", &n);
        printf("%lld\n", sol(n));
    }
    return 0;
}
