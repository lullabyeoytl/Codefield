#include <bits/stdc++.h>
using namespace std;
int bp[1003][1003];
int a[1003][1003];
int n,m;
int dx[5]={0,1,0,-1,0};
int dy[5] = {0,0,1,0,-1};
typedef pair<int,int> P;
void bfs(int i,int j)
{
    queue <P> que;
    que.push(P(i,j));
    bp[i][j]=0;
    que.push(P(i,j));
    while(que.size())
    {
        P p = que.front();
        que.pop();
        for(int i=1;i<=4;i++)
        {
            int nx = p.first+dx[i];
            int ny= p.second + dy[i];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=n&&bp[nx][ny]==-1&&a[nx][ny]+a[p.first][p.second]==1)
            {
                que.push(P(nx,ny));
                bp[nx][ny] = bp[p.first][p.second]+1;
            }
        }
    }
    

}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<=m;i++)
    {
        int k,j;
        scanf("%d%d",&k,&j);
        memset(bp,-1,sizeof(bp));
        bfs(k,j);
        int cnt=0;
        for(int a=1;a<=n;a++)
        {
            for(int b=1;b<=n;b++)
            {
                if(bp[a][b]!=-1)
                {
                    cnt++;
                }
            }
        }
        printf("%d\n",cnt);
        
    }
    return 0;
}
/*
#include<cstdio>
#include<cstring>
int n,m,ans[100002],x,y,f[1002][1002];
char s[1002][1002];
void dfs(int r,int c,int z,int lll){
    if (r<0 || r>=n || c<0 || c>=n || f[r][c]!=-1 || s[r][c]-'0'!=z)return;
    f[r][c]=lll;ans[lll]++;
    dfs(r-1,c,!z,lll);dfs(r+1,c,!z,lll);dfs(r,c-1,!z,lll);dfs(r,c+1,!z,lll);
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++)
    scanf("%s",s[i]);
    memset(f,-1,sizeof(f));
    for (int i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);x--;y--;
        if (f[x][y]==-1)dfs(x,y,s[x][y]-'0',i);else ans[i]=ans[f[x][y]];
    }
    for (int i=0;i<m;i++)
    printf("%d\n",ans[i]);
    return 0;
}

*/
/*
  if(dp[nx][ny]==0 && w!=b && nx>0 && ny>0 && nx<=n && ny<=n)
             {                  
                                
                                sum++;
                                dp[nx][ny]=1;
                                bp[nx][ny]=bp[x][y]+1;
                                que.push(P(nx,ny));
             }

*/