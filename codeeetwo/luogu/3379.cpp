#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=500000+2;
int n,m,s;
int k=0;
int head[maxn],d[maxn],p[maxn][21];
struct node{
    int v,next;
}e[maxn*2];//存树
void add(int u,int v)
{
    e[k].v=v;
    e[k].next=head[u];
    head[u]=k++;
}               //加边函数
void dfs(int u,int fa)
{
    d[u]=d[fa]+1;
    p[u][0]=fa;
    for(int i=1;(1<<i)<=d[u];i++)
        p[u][i]=p[p[u][i-1]][i-1];
    for(int i=head[u];i!=-1;i=e[i].next)
    {
        int v=e[i].v;
        if(v!=fa)
            dfs(v,u);
    }
}                              
int lca(int a,int b)                                          
{
    if(d[a]>d[b])
        swap(a,b); 
    for(int i=20;i>=0;i--)
        if(d[a]<=d[b]-(1<<i))
            b=p[b][i];            
    if(a==b)
        return a;   
    for(int i=20;i>=0;i--)
    {
        if(p[a][i]==p[b][i])
            continue;
        else
            a=p[a][i],b=p[b][i]; 
    }
    return p[a][0];  
}
int main()
{
    memset(head,-1,sizeof(head));
    int a,b;
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a);             
    }
    dfs(s,0);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",lca(a,b));
    }
    return 0;
}