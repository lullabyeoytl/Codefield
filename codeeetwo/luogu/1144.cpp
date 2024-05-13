#include <cstdio>
#include <algorithm>
#include <queue>
int tot,edge[4000006],next[4000006],head[4000006],ver[4000006];
void add(int x,int y,int z)//加入有向边（x,y),权值为z
{
    ver[++tot]=y;edge[tot]=z;
    next[tot]=head[x];head[x]=tot;//在表头x处插入
}
int ans[1000006],len[1000006];
void bfs()
{
    std::queue<int> q;
    q.push(1);len[1]=1;ans[1]=1;
    while(q.size())
    {
        int to = q.front();
        q.pop();
        for(int i=head[to];i;i=next[i])
        {
            int y=ver[i],z=edge[i];
            if(!len[y])
            {
                len[y]=len[to]+1;
                ans[y]++;
                ans[y]%=100003;
                q.push(y);
            }
            else
            {
                if(len[y]==len[to]+1) 
                {
                    ans[y]++;
                    ans[y]%=100003;
                    q.push(y);
                }
            }
        }
    }
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y,1);
        add(y,x,1);
    }
    bfs();
    for(int i=1;i<=n;i++)
    {
        printf("%d\n",ans[i]);
    }
    return 0;
}