#include <bits/stdc++.h>
using namespace std;
int dp[10001][10001];
int a[10001];
int s[10001];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        s[i]=s[i-1]+a[i];
    }
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i<=n-len+1;i++)
        {
            int j=i+len-1;dp[i][j]=1<<31-1;
            for(int k=i;k<=j-1;k++)
            {
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
            }
            dp[i][j]+=s[j]-s[i-1];
        }
    }
    printf("%d",dp[1][n]);
    system("pause");
    return 0;
}