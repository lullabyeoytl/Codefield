#include <bits/stdc++.h>
using namespace std;
int dp[2005][1001];
int a[2005];
int main()
{
    int con = pow(10,8); 
    int n,f;
    scanf("%d%d",&n,&f);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i]%=f;
    }
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        dp[i][a[i]]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=f-1;j++)
        {
            dp[i][j] = (dp[i][j]%f+dp[i-1][j]%f + dp[i-1][(j-a[i])%f])% con;
        }
    }
    printf("%d",dp[n][0]);
    system("pause");
    return 0;
}