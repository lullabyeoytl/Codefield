#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,k,d;
ll a[101];
ll dp[101][101][101];
ll lmax (ll a,ll b,ll c) 
{
    ll s1= max(a,b);
    return max(s1,c);
} 

int main()
{
    memset(dp,0,sizeof(dp));
    scanf("%d%d%d",&n,&k,&d);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<d;i++)
    {
        dp[i][0][0]=0;
    }
    for(int ki=1;ki<=k;ki++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int i=0;i<d;i++)
            {
                dp[i][j][ki]=lmax(dp[i][j-1][ki],dp[(i-a[j])%d][j-1][ki-1]+a[j],-1);

            }
        }
    }
    if(!dp[0][n][k])
    printf("%lld",dp[0][n][k]);
    else
    printf("-1");
    system("pause");
    return 0;


}