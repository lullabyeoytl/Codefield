#include <bits/stdc++.h>
using namespace std;
#define pi 1000007 
int n,m;
int a[105];
int dp[105][105];
int main()
{
    memset(dp,0,sizeof(dp));
    scanf("%d%d",&n,&m);
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        dp[i][i]=1;
    }
    for(int i=1;i<=a[1];i++)
    dp[1][i]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=m;j>=i;j--)
        {
            for(int k=1;k<=a[i];k++)
            {
                if(j>=i+k-1)
                {
                    dp[i][j]=(dp[i][j]+dp[i-1][j-k])%pi;
                }
            }
        }
    }
    printf("%d",dp[n][m]);
    system("pause");
    return 0;
}
