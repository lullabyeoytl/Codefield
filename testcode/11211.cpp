#include <bits/stdc++.h>
using namespace std;
long long dp[35][35];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    dp[0][0]=1;
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<=n-1;j++)
        {
            dp[i][j]=dp[i-1][(j+n-1)%n]+dp[i-1][(j+1)%n];

        }
    }
    printf("%lld",dp[m][0]);
    system("pause");
    return 0;
}