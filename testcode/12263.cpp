#include<bits/stdc++.h>
using namespace std;
int dp[30][10000],f[30],d[30],t[30];
int n,h,ans=-1;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
        x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int main(){
    n=read();h=read();
    h*=12;
    for(int i=1;i<=n;++i)
        f[i]=read();
    for(int i=1;i<=n;++i)
        d[i]=read();
    for(int i=1;i<n;++i)
        t[i]=read();
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=h;++j)
        {
            for(int k=0;k<=j-t[i-1];++k)
                if((k-1)*d[i]<f[i]&&dp[i-1][j-t[i-1]-k]!=-1)
                {
                    dp[i][j]=max(dp[i][j],dp[i-1][j-t[i-1]-k]+k*f[i]-k*(k-1)/2*d[i]);
                    ans=max(ans,dp[i][j]);
                }
        }
    cout<<ans<<endl;
    return 0;
}