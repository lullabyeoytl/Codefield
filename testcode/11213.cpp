#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
int dp[17][17];
int s[17];
int mem[17];
 int n,k;
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
long long dfs(int pos,int id)
{
    mem[id]=1;
    if(dp[pos][id]!=0)return dp[pos][id];
    if(pos==1)return 1;
    else
    {
        for(int j=1;j<=n;j++)
        {
            if(abs((s[j]-s[id]))>k&&mem[j]==0)
            {
                mem[j]=1;
                dp[pos][id]+=dfs(pos-1,j);
                mem[j]=0;
            }
        }
        mem[id]=0;
        return dp[pos][id];
    } 
}
int main()
{
    n=read();k=read();
    for(int i=1;i<=n;i++)
    {
        s[i]=read();
    }
    sort(s+1,s+n+1);
    for(int i=1;i<=n;i++)
    {
        dp[1][i]=1;
    }
    int t=0;
    for(int i=1;i<=n;i++)
    {
        t+=dfs(n,i);
    }
    printf("%d",t);
    system("pause");
    return 0;
}