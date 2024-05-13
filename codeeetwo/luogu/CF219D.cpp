#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <cstdio>
#include <cstring>
const int maxn = 200005;
int ver[2*maxn],edge[2*maxn],next[2*maxn],head[2*maxn];
int tot;
inline void add(int x,int y,int z)//加入有向边（x,y),权值为z
{

    ver[++tot]=y;edge[tot]=z;
    next[tot]=head[x];head[x]=tot;//在表头x处插入
}
int dp[maxn];
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
int dfs(int x,int fa)
{
    int num=0;
    for(int i=head[x];i;i=next[i])
    {
        int y=ver[i],z=edge[i];
        if(y==fa)continue;
        else
        {
            num+=z;
            dfs(y,x);
            num += dfs(y,x);
        }
    }
    return num;
}

inline void dfs2(int x,int fa)
{
    for(int i=head[x];i;i=next[i])
    {
        int y=ver[i],z=edge[i];
        if(y==fa)continue;
        else
        {
            if(z==2)
            {
                dp[y]=dp[x]-1;
                dfs2(y,x);
            }
            if(z==1)
            {
                dp[y]=dp[x]+1;
                dfs2(y,x);
            }
        }
    }
}
int main()
{
    int n=read();
    for(int i=1;i<n;i++)
    {
        int x,y;
        x=read();y=read();
        add(x,y,1);
        add(y,x,2);
    }
    dp[1] = dfs(1,0)-n+1;
    dfs2(1,0);
    int maxnn=2*maxn;
    for(int i=1;i<=n;i++)
    {
        maxnn=(dp[i]<maxnn)?dp[i]:maxnn;
    }
    printf("%d\n",maxnn);
    for(int i=1;i<=n;i++)
    {
        if(dp[i]==maxnn)
        printf("%d ",i);
    }
    return 0;
}
