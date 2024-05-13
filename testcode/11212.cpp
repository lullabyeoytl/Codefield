#include <bits/stdc++.h>
using namespace std;
#define pi 1000000007
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
long long dp[2][7];
int lin[7][7];
int mol[7]={0,4,5,6,1,2,3};
int main()
{
    int n,m;
    n=read();m=read();
    for(int i=1;i<=m;i++)
    {
        int a,b;
        a=read();b=read();
        lin[a][b]=1;lin[b][a]=1;
    }
    for(int i=1;i<=6;i++)
    {
        dp[1][i]=4;
    }
    for(int j=2;j<=n;j++)
    {
        if(j%2==0)
        {
            for(int i=1;i<=6;i++)
            {
                long long temp=0;
                for(int k=1;k<=6;k++)
                {
                    if(lin[mol[i]][k]==0)
                    {
                        temp+=dp[1][k]<<2;
                        temp%=pi;
                    }
                }
                dp[0][i]=temp;
            }
        }
        else
        {
            for(int i=1;i<=6;i++)
            {
                long long temp=0;
                for(int k=1;k<=6;k++)
                {
                    if(lin[mol[i]][k]==0)
                    {
                        temp+=dp[0][k]<<2;
                        temp%=pi;
                    }
                }
                dp[1][i]=temp;
            }
        }
    }
    long long ans=0;
    if(n==1)
    {
        printf("24");
        return 0;
    }
    for(int i=1;i<=6;i++)
    {
        if(dp[n%2][i]==4)
        continue;
        ans+=dp[n&1][i];
        ans%=pi;
    }
    printf("%lld",ans);
    return 0;
}