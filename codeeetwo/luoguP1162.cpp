#include <bits/stdc++.h>
using namespace std;
int n;
int a[35][35];
int dx[5] = {0,1,0,-1,0};int dy[5] = {0,0,1,0,-1};
int dp[35][35];
void dfs(int x,int y,int x0,int y0)
{
    for(int i =1;i<=4;i++)
    {
        int nx = x+dx[i];int ny = y+dy[i];
        if(nx == x0&&ny == y0)return ;
        else
        {
            if(nx>=1&&nx<=n&&ny>=1&&ny<=n&&dp[nx][ny]==-1&&a[nx][ny]==1)
            {
                dp[nx][ny] = 1;
                dfs(nx,ny,x0,y0);
                dp[nx][ny] = -1;
            }
        }
    }
    return ;
}

int main()
{
    scanf("%d",&n);
    for(int i = 1; i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
     memset(dp,-1,sizeof(dp));
     for(int i = 1; i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            if(a[i][j]==1)
            {
               
                dp[i][j] = 1;
                dfs(i,j,i,j);
            }
        }
    }
     for(int i = 1; i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            if(dp[i][j]==1)
            {
                for(int k =j+1;a[i][k]==0 ; k++)
                {
                    a[i][k]=2;
                }
            }
        }
    }
     for(int i = 1; i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            if((i==1||i==n||j==1||j==n)&&a[i][j]!=1)
            a[i][j]=0;
        }
    }
    for(int i = 1; i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;


}