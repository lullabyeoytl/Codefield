#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
long long s[200005];
typedef pair<int,int> P;
long long dp[200005];
long long dp1[200005];
int pos[200005];
long long maxn(long long a,long long b,long long c)
{
    long long s1= max(a,b);
    return max(s1,c);
}
int main()
{
    scanf("%d",&n);
    s[0]=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        s[i]=s[i-1]+a[i];
    }
    dp[0]=0;P p;
    p.first=0;p.second = 0;
    for(int i=1;i<=n;i++)
    {
        dp1[i]=max(dp1[i-1]+a[i],a[i]);
        if(dp1[i]==a[i])
        pos[i]=i;
        else
        pos[i]=pos[i-1];
        dp[i]=maxn(dp1[i],dp[i-1],dp[i-1]+s[i]-s[p.second]);
        if(maxn(a[i],dp1[i-1],dp[i-1]+s[i]-s[p.second])==dp1[i])
        {
            p.first=pos[i];p.second = i;
        }
        else if(maxn(a[i],dp1[i-1],dp[i-1]+s[i]-s[p.second])==dp[i-1]+s[i]-s[p.second])
        {
            p.second = i;
        }
    }
    long long maxnn=-9223372036854775808;
    for(int i=1;i<=n;i++)
    {
        maxnn=max(maxnn,dp1[i]);
    }
    printf("%lld",maxnn);
    system("pause");
    return 0;
}