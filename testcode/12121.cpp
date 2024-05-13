#include <cstdio>
int n,m,tot;
const int maxn=3005;
int ver[2*maxn],edge[2*maxn],next[2*maxn],head[2*maxn];
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
void add(int x,int y,int z)//加入有向边（x,y),权值为z
{

    ver[++tot]=y;edge[tot]=z;
    next[tot]=head[x];head[x]=tot;//在表头x处插入

}
int moy[maxn];
int dp[maxn];
int numres=0;
int dfs(int x, int fa)
{
    if(moy[x]!=0)
    {
        int i=head[x];
        int z=edge[i];
        if(moy[x]>z)
        {
            dp[x]=1;
        }
        return moy[x]-z;
    }
    else{
        int cnt=0;int numtemp=0;
    for(int i = head[x];i;i=next[i])
    {
        int y=ver[i];int z=edge[i];
        if(y==fa)
        {
            cnt-=z;
        }
        else
        {
            int numnow=dfs(y,x);
            if(numnow>=0) {
                cnt+=numnow;
                numtemp+=dp[y];
            }
        }
    }
    int res = cnt>0 ? cnt : 0;
    if(res==cnt)
    {
        dp[x]=numtemp;
    }
    return res;
    
    }
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=n-m;i++)
    {
        int inum=read();
        for(int j=1;j<=inum;j++)
        {
            int x=read(),y=read();
            add(i,x,y);add(x,i,y);
        }
    }
    for(int i=1;i<=m;i++)
    {
        moy[n-m+i]=read();
    }
    int sol=dfs(1,0);
    printf("%d",dp[1]);
    return 0;
}    