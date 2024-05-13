#include <cstdio>
#include <cstring>
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
bool vis[200005];
int fa[200005];
int icheck;
void dfs(int x)
{
    if(vis[x])
    {
        icheck=x;
        return;
    }
    else
    {
        vis[x]=1;
        dfs(fa[x]);
    }
}
int cnt=0;
void dfs1(int x)
{
    if(vis[x])
    return;
    else
    {
        vis[x]=1;
        cnt++;
        dfs1(fa[x]);
    }
    return ;
}
int main()
{
    int n=read();
    for(int i=1;i<=n;i++)
    {
        fa[i]=read();
    }
    dfs(1);
    int x=icheck;
    memset(vis,0,sizeof(vis));
    dfs1(x);
    printf("%d",cnt);
    return 0;
}

#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int dx[300000];//存每一个人传话的对象
bool visit[300000]={0},novisit[300000]={0};//visit存每次查找中被查到的点，而novisit存每次查找前，已经被查找过的点（及不用继续查找了）
int bs[300000]={0};//每次查找中第一次到一个节点所经过的边数
int minn=2e9;
void dfs(int node,int num)
{
    if(novisit[node])return;//不需要继续找了
    if(visit[node])//在此次查找中出现过
    {
        minn=min(minn,num-bs[node]);//形成一个环，取最小值
    }
    else
    {
        visit[node]=true;//在此次循环中经过
        bs[node]=num;//记录第一次到达时的步数
        dfs(dx[node],num+1);//搜索
        novisit[node]=true;//已经搜过
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&dx[i]);
    }
    for(int i=1;i<=n;i++)
    {
        dfs(i,0);//枚举全部节点
    }
    printf("%d",minn);//输出
    return 0;//时间复杂度O(n)
}