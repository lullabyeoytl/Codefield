/*
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
int r,c;
int a[105][105];
int bp[105][105];
int dx[5]={0,1,0,-1,0};
int dy[5]={0,0,1,0,-1};
int bfs(int x,int y)
{
    queue <P> que;
    que.push(P(x,y));
    bp[x][y]=0;
    while(que.size())
    {
        P p =que.front();
        que.pop();int cnt = 1;
        for(int i=1;i<=4;i++)
        {
            int ix = p.first +dx[i];
            int iy = p.second +dy[i];
            if(a[ix][iy]!=-1&&a[ix][iy]<a[p.first][p.second])
            {
                cnt=0;
            }
        }
        if(cnt){return bp[p.first][p.second];}
        else{
        for(int i=1;i<=4;i++)
        {
            int nx=p.first+dx[i];
            int ny = p.second +dy[i];
            if(nx>=1&&nx<=r&&ny>=1&&ny<=c&&bp[nx][ny]==-1&&a[nx][ny]<a[p.first][p.second])
            {
                que.push(P(nx,ny));
                bp[nx][ny]=bp[p.first][p.second]+1;
            }

        }
        }
    }
    
}
int main()
{
    scanf("%d%d",&r,&c);
    memset(a,-1,sizeof(a));
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int maxn =-1;
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            memset(bp,-1,sizeof(bp));
            if(bfs(i,j)>maxn)maxn=bfs(i,j);
        }
    }
    printf("%d",maxn);


    
    


    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int n,m,a[201][201],dp[201][201],ans=0;
bool use[201][201];
int dfs(int x,int y){
    if(dp[x][y])return dp[x][y];
    dp[x][y]=1;
    for(int i=0;i<4;i++)
    {  int nx=dx[i]+x;
       int ny=dy[i]+y;
       if(nx>0&&ny>0&&nx<=n&&ny<=m&&a[x][y]>a[nx][ny])
       {
       	  dfs(nx,ny);
          dp[x][y]=max(dp[x][y],dp[nx][ny]+1);
       }
    }
    return dp[x][y];
}
int main()
{	
   scanf("%d%d",&n,&m);
   for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++)
       scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
        ans=max(ans,dfs(i,j));
    printf("%d",ans);
    return 0;
}
