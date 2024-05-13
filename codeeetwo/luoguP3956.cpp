#include <bits/stdc++.h>
int m,n;
int a[105][105]; int dp[105][105];
int temp[105][105];
int dx[5]={0,1,0,-1,0}; int dy[5] = {0,0,1,0,-1};
int check = 0;
int monsum=0;
int mid;
void dfs(int x,int y)
{
    if(x==m && y==m)
    {
        if(monsum<=mid)check=1;
    }
    for(int i =1;i<=4;i++)
    {
       int nx = x+dx[i]; int ny = y+dy[i];
       if(nx>=1&&nx<=m&&ny>=1&&ny<=m&&dp[nx][ny] == 0&&monsum<=mid)
       {
            if(a[x][y]==0)
            {
                if(a[nx][ny]==0)
                {
                    dp[nx][ny] = 1;
                    dfs(nx,ny);
                    if(check==1)return;
                }
                if(a[nx][ny]==1)
                {
                    monsum+=1;
                    dp[nx][ny] = 1;
                    dfs(nx,ny);
                }
                else
                {
                    monsum+=2;
                    dp[nx][ny]=1;
                    for(int j=0;j<=1;j++)
                    {
                        temp[nx][ny]=j;
                        dfs(nx,ny);
                    }
                }
            }
            else if(a[x][y]==1)
            {
                if(a[nx][ny]==0)
                {
                    monsum+=1;
                    dp[nx][ny] = 1;
                    dfs(nx,ny);
                }
                if(a[nx][ny]==1)
                {
                    
                    dp[nx][ny] = 1;
                    dfs(nx,ny);
                }
                else
                {
                    monsum+=2;
                    dp[nx][ny]=1;
                    for(int j=0;j<=1;j++)
                    {
                        temp[nx][ny]=j;
                        dfs(nx,ny);
                    }
                }
                
            }
            else
            {
                if(((temp[x][y]==0&&a[nx][ny]==0)||temp[x][y]==1&&a[nx][ny]==1)&&monsum<=mid)
                {
                    monsum += a[nx][ny];
                    dp[nx][ny] = 1;
                    dfs(nx,ny);
                }
            }
        }
    }
}

int main()
{
    memset(a,-1,sizeof(a));
    scanf("%d%d",&m,&n);
    for(int i = 1;i<=n;i++)
    {
        int x,y,to;
        scanf("%d%d%d",&x,&y,&to);
        a[x][y]=to;
    }
    int lo = 0;int hi = 100000;
    while(lo<=hi)
    {
        memset(dp,0,sizeof(0));
        memset(temp,-1,sizeof(temp));
        check = 0;
        monsum = 0;
        mid = (lo+hi)/2;
        dp[1][1]=1;
        dfs(1,1);
        if(check)hi = mid-1;
        else lo = mid+1;
    }
    printf("%d",monsum);
    return 0;
}
