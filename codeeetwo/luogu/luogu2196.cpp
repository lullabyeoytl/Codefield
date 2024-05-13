#include <bits/stdc++.h>
using namespace std;
int n,a[25];
int b[25][25];
int dp[25];
int res[25];
int maxn;
int ans;
int dfs(int x)
{
    int cnt=0;
    for(int i=1;dp[i]!=0&&b[x][i]==1;i++)
    {
        dp[i]=1;
        ans+=res[i];//一开始res初始化为地雷书a[i];
        dfs(i);
        ans-=res[i];
        dp[i]=0;
    }
    if(!cnt)
    {
        return maxn=max(ans,maxn);
    }
    return maxn;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        res[i]=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            scanf("%d",&b[i][j]);
            b[j][i]=b[i][j];
        }
    }
    int maxnn=-1;
    for(int i=1;i<=n;i++)
    {
        memset(dp,0,sizeof(dp));
        dp[i]=1;
        ans=a[i];
        maxn=0;
        maxnn=max(maxnn,dfs(i));
    }
    printf("%d",maxnn);
    system("pause");
    return 0;
}