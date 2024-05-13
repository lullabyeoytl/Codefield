#include <cstdio>
#include <algorithm>
using namespace std;
int s,n,m,dp[20002],a[110][110],ans;
int main()
{
    scanf("%d %d %d", &s, &n, &m);
    for(int i=1;i<=s;++i)
        for(int j=1;j<=n;++j)
            scanf("%d", &a[j][i]);
    for(int i=1;i<=n;++i)
        sort(a[i]+1, a[i]+1+s);
    for(int i=1;i<=n;++i)
        for(int j=m;j>=0;--j) 
            for(int k=1;k<=s;++k) 
                if(j>a[i][k]*2)
                    dp[j]=max(dp[j-a[i][k]*2-1]+k*i, dp[j]);
    for(int i=0;i<=m;++i) ans=max(ans, dp[i]);
    printf("%d\n", ans);
    return 0;
}