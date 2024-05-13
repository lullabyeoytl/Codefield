#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
int n,m,x,y;
int dx[10]={0,2,1,-1,-2,-2,-1,1,2};
int dy[10]={0,1,2,2,1,-1,-2,-2,-1};
int bp[401][401];//计步数
int check[401][401];//记忆化
int bfs(int i,int j)
{
    memset(bp,-1,sizeof(bp));
    memset(check,0,sizeof(check));
    queue <P> que;
    que.push(P(x,y));
    bp[x][y]=0;//0表示起点
    check[x][y]=1;
    while(que.size())
    {
      P p = que.front();
      que.pop();//从队列中去除最前的元素，相当于一种回溯
      if(p.first==i && p.second == j)break;
      for(int a = 1;a<=8;a++)
      {
        int nx = p.first+dx[a];int ny = p.second + dy[a];
        if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&bp[nx][ny]==-1&&check[nx][ny]==0)
        {
            que.push(P(nx,ny));
            bp[nx][ny] = bp[p.first][p.second]+1;
            check[nx][ny] = 1;//记忆化
        }
      }
    }
    return bp[i][j];

}
int main()
{
    scanf("%d%d%d%d",&n,&m,&x,&y);
    for(int i = 1;i<=n;i++)
    {
        for(int j  =1;j<=m;j++)
        {
            printf("%d ",bfs(i,j));
        }
        if(i!=n)
        printf("\n");
    }
    return 0;

}