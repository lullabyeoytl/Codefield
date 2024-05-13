#include <bits/stdc++.h>
using namespace std;
int v[50004],size[50004],dist[50004];
int ver[50004],edge[50004],head[50004],nxt[50004];
int tot,n;
int pos,ans,res;
queue <int> q;
void add(int x,int y,int z)//加入有向边（x,y),权值为z
{
    ver[++tot]=y;edge[tot]=z;
    nxt[tot]=head[x];head[x]=tot;//在表头x处插入
}

void dfs(int x){
    v[x]=1;size[x]=1;//v记录是否访问过，size记录删除x后分成的最大子树的大小
    int max_part = 0;
    for(int i=head[x];i;i=nxt[i]){
        int y = ver[i];
        if(v[y])continue;
        dfs(y);
        size[x] += size[y];//从子节点向父节点递推
        max_part = max(max_part,size[y]);
    }
    max_part = max(max_part,n-size[x]);
    if(max_part<ans){
        ans=max_part;//全局变量ans记录重心对应的max_part值
        pos=x;//全局变量pos记录了重心
    }
}

void bfs()
{
    q.push(pos);
    v[pos]=1;
    while(q.size())
    {
        int to = q.front();
        q.pop();
        for(int i =head[to];i;i=nxt[to])
        {
            int yy=ver[i];
            if(v[yy]==0)
            {
            dist[yy]=dist[to]+1;
            res+=dist[yy];
            q.push(yy);
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b,1);add(b,a,1);
    }
    dfs(1);
    memset(v,0,sizeof(v));
    bfs();
    printf("%d %d",pos,res);
    system("pause");
    return 0;

}