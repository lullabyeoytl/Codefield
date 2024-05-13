#include <cstdio>
#include <cstring>
#include <cstdlib>
int n,m,t;
int r1,c1,r2,c2;
char a[105][105];
int dp[105][105][17];
int res;
int dx[5]={0,1,0,-1,0};
int dy[5]={0,0,1,0,-1};
int dfs(int x,int y,int ti)//走ti秒到目的地
{
    if(ti<0)
    return 0;
    else if(x<0||y<0||x>n||y>n)
    return 0;
    else if(a[x][y]=='*')
    return 0;
    else if(ti>=t+1||ti<0)
    return 0;
    else if(x==r2&&y==c2&&ti==0)
    return 1;
    else if(ti==0)
    return 0;
    else
  {
    if(dp[x][y][ti]!=-1)
    return dp[x][y][ti];
    else
    {
        int sum=0;
        for(int i=1;i<=4;i++)
        {
            int nx=x-dx[i];int ny = y-dy[i];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]=='.')
            {
                if(dp[nx][ny][ti+1]!=-1)
                {
                    sum+=dp[nx][ny][ti+1];
                }
                else
                {
                    dp[nx][ny][ti+1] = dfs(nx,ny,ti+1);
                    sum += dp[nx][ny][ti+1];
                }
            }
        }
        return sum;
    }
  }  

}
int main()
{
    memset(dp,-1,sizeof(dp));
   scanf("%d%d%d",&n,&m,&t);
   getchar();
   for(int i=1;i<=n;i++)
   {
      gets(a[i]);
    }
   scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
   printf("%d\n",dfs(r1,c1,t+1));
    system("pause");
    return 0;


}
