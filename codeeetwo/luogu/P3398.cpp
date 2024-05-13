/*
#include <cstdio>
#include <queue>
const int size = 100010;
 int f[size][20],d[size],dist[size];
 int ver [2*size],next[2*size],edge[size*2],head[size];
 int T,n,m,tot,t;
 std::queue <int> q;

 void add(int x,int y,int z)
 {

    ver[++tot]=y;edge[tot]=z;next[tot]=head[x];head[x]=tot;
 }//邻接表

 void bfs(){

    //预处理
    q.push(1);d[1]=1;
    while(q.size()){
        int x =q.front();q.pop();
        for(int i=head[x];i;i=next[i]){
            int y = ver[i];
            if(d[y])continue;
            d[y]=d[x]+1;
            dist[y]=dist[x]+edge[i];
            f[y][0]=x;
            for(int j=1;j<=t;j++)
           f[y][j]=f[f[y][j-1]][j-1];
           q.push(y);
        }
    }
 }

 int lca(int x,int y)//回答一个询问
 {

    if(d[x]>d[y])std::swap(x,y);
    for(int i=t;i>=0;i--)
    if(d[f[y][i]]>=d[x])y=f[y][i];
    if(x==y)return x;
    for(int i=t;i>=0;i--)
    if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
    return f[x][0];
 }

int len_xyzcheck(int x,int y, int z)
{
    if(dist[x]+dist[y]-2*dist[lca(x,y)]==(dist[x]+dist[z]-2*dist[lca(x,z)])+(dist[z]+dist[y]-2*dist[lca(z,y)]))
    {
        return 1;
    }
    else
    return 0;
}

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

int main()
{
    int q;
    n=read();q=read();
    for(int i=1;i<n;i++)
    {
        int u=read(),v=read();
        add(u,v,1);add(v,u,1);
    }

    for(int i=1;i<=q;i++)
    {
        int a=read(),b=read(),c=read(),d=read();
        int ab_fa=lca(a,b);
        int cd_fa=lca(c,d);
        if(len_xyzcheck(a,b,cd_fa)||len_xyzcheck(c,d,ab_fa))printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define MAXN 100000+15 
using namespace std;
vector<int>vec[MAXN];
int n,q,v,u,a,b,c,d;
int deep[MAXN],dad[MAXN],size[MAXN],top[MAXN];
int dfs(int x){
    size[x]=1;
    deep[x]=deep[dad[x]]+1;
    for(int i=0;i<vec[x].size();i++)
        if(dad[x]!=vec[x][i]){
            dad[vec[x][i]]=x;
            dfs(vec[x][i]);
            size[x]+=size[vec[x][i]]; 
        } 
    return 0;
} 
int dfs1(int x){
    int t=0;
    if(!top[x])    top[x]=x;
    for(int i=0;i<vec[x].size();i++)
        if(dad[x]!=vec[x][i]&&size[vec[x][i]]>size[t])
            t=vec[x][i];
    if(t){
        top[t]=top[x];
        dfs1(t);
    }    
    for(int i=0;i<vec[x].size();i++)
        if(dad[x]!=vec[x][i]&&vec[x][i]!=t)
            dfs1(vec[x][i]);
    return 0;
}
int LCA(int x,int y){
    for(;top[x]!=top[y];){
        if(deep[top[x]]<deep[top[y]])
            swap(x,y);
        x=dad[top[x]];
    }
    if(deep[x]>deep[y])    swap(x,y);
    return x;
}
int main(){
    cin>>n>>q;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    dfs(1);
    dfs1(1);
    for(int i=1;i<=q;i++){
        cin>>a>>b>>c>>d;
        int S=LCA(a,b);
        int T=LCA(c,d);
        if(deep[S]<deep[T]){
            swap(S,T);
            swap(a,c);
            swap(b,d);
        }    
        if(LCA(S,c)==S||LCA(S,d)==S)    cout<<"Y"<<endl;
        else    cout<<"N"<<endl;
    }
    return 0;
}
