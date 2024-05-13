#include <bits/stdc++.h>
using namespace std;
int a[3][105];int dp[3][105];
int check;
int k[105];
int res[105];
int dy[10]={0,0,1,1,1,0}; int dx[10] = {0,-1,-1,0,1,1};
void dfs(int x,int y,int n)
{
    if(x==2&&y==n) 
    {
        
        check =1;
        printf("Yes\n");
        return ;
    }
    for(int i=1;i<=5;i++)
    {
        int nx = x+dx[i];int ny = y + dy[i];
        if(nx>=1&&nx<=2 &&ny<=n&&a[nx][ny]==0&&dp[nx][ny]==0)
        {
            dp[nx][ny] = 1;
            dfs(nx,ny,n);
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    memset(res,-1,sizeof(res));
    for(int i =1;i<=t;i++)
    {
        memset(dp,0,sizeof(dp));
        check =0;
        scanf("%d",&k[i]);
        for(int j = 1;j<=2;j++)
        {
            for(int b = 1;b<=k[i];b++)
            {
                scanf("%d",&a[j][b]);
            }
        }
        dp[1][1]=1;
        dfs(1,1,k[i]);
        if(check==0)
        {
            res[i]=0;
            continue;
        }
        else if(i==t)
        {
            break;
        }
        else
        continue;
        
    }
    for(int i =1;i<=t;i++)
    {
        int temp = 1;
        if(res[i]==0)
        {
            printf("NO\n");temp  =0;
        }
        if(temp)printf("YES\n");

       
    }

    return 0;
}