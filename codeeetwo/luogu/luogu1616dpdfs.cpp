/*
#include <bits/stdc++.h>
using namespace std;
int tmax,m;
int ti[1001]; int pi[1001];
long long dp[100007][100007][1001];
int pmax=0;
int dfs(int t, int p,int mi)
{
    if(mi>=m+1)
    {
        return pmax=max(p,pmax);
    }
    if(t>tmax)
    {
        return 0;
    }
    for(int k=(tmax-t)/ti[mi];k>=0;k--)
    {
        if(dp[t+k*ti[mi]][p+k*pi[mi]][mi+1])  
        return pmax = max(dp[t+k*ti[mi]][p+k*pi[mi]][mi+1],pmax);
        else 
        dp[t+k*ti[mi]][p+k*pi[mi]][mi+1]=dfs(t+k*ti[mi],p+k*pi[mi],mi+1);
    }
    return pmax;
}
int main()
{
    scanf("%lld%lld",&tmax,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%lld%lld",&ti[i],&pi[i]);
    }
    printf("%lld",dfs(0,0,1));
    return 0;
}
*/

