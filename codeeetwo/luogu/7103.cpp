#include <cstdio>
#include <queue>
const int size = 5000010;
 int f[size][20],d[size],dist[size];
 int ver [2*size],next[2*size],edge[size*2],head[size];
 int T,n,m,tot,t;
 std::queue <int> q;

 void add(int x,int y,int z)
 {

    ver[++tot]=y;edge[tot]=z;next[tot]=head[x];head[x]=tot;
 }//邻接表

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
    for(int i=20;i>=0;i--)
    if(d[f[y][i]]>=d[x])y=f[y][i];
    if(x==y)return x;
    for(int i=20;i>=0;i--)
    if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
    return f[x][0];
 }

int fl_lca[size];

int main()
{
    n=read();m=read();
    for(int i=1;i<=n;i++)
    {
        int x;
        x=read();
        if(i==1)continue;
        add(x,i,1);add(i,x,1);
    }
    bfs();
    fl_lca[1]=1;fl_lca[2]=1;
    for(int i=1;i<=n;i++)
    {
        if(d[i]==1||d[i]==2)continue;
        else 
        {
            if(fl_lca[d[i]]==0)fl_lca[d[i]]=i;
            else
           {
                if(fl_lca[d[i]]==1)
                 continue;
                 else
                fl_lca[d[i]]=lca(fl_lca[d[i]],i);
           }
        }
    }
    for(int i=1;i<=m;i++)
    {
        int x=read();
        printf("%d\n",fl_lca[x]);
    }
    return 0;
}

