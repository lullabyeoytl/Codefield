#include <cstdio>
#include <cstring>
int n,m;
int a[505][505];
int dp[505][505];
int mp[505][505];// mp[i][j]:from a[n][i] able to a[1][j]
int dx[5] = {0,1,0,-1,0}; int dy[5]={0,0,1,0,-1};
int check;
int res = 0;
void dfs(int i,int x,int y)// from a[n][i]
{
    if(x==1)
    {
        if(a[1][y]>a[1][y-1]&&a[1][y]>a[1][y+1])
        {
            check=1;
            a[i][y]=1;
            return ;
        }
        else
        {
            for(int i =0;i<=1;i++)
            {
                int ny= y+i*2-1;
                if(a[1][ny]>a[x][y]&&dp[1][ny]==0)
                {
                    dfs(i,x,ny);
                }
            }
        }
    }
    else
    {
        for(int i=1;i<=4;i++)
        {
            int nx=x+dx[i],ny = y+dy[i];
            if(dp[nx][ny]==0&&nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]>a[x][y])
            {
                dp[nx][ny]=1;
                dfs(i,nx,ny);
                dp[nx][ny]=0;//回溯
                continue;
            }
        }
    }

}
int main()
{
    memset(mp,0,sizeof(mp));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int cnt=0;
    for(int i=1;i<=m;i++)
    {
        int check=0;
        memset(dp,0,sizeof(dp));
        dp[n][i]=1;
        dfs(i,n,i);
        if(!check)
        {
            cnt += 1;
        }
    }
    if(cnt)
    {
        printf("0\n");
        printf("%d\n",cnt);
    }
    else
    {
        printf("1\n");
      
    }
    return 0;
} 