#include <bits/stdc++.h>
using namespace std;
long long dp[1005];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    dp[0]=1;
    for(int i=1;i<=k;i++)
    {
        for(int j=i;j<=n;j++)
        {
                dp[j]+=dp[j-i];
        }
    }
    printf("%lld",dp[n]);
    system("pause");
    return 0;
}