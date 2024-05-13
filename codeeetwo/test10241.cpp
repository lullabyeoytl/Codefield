#include<bits/stdc++.h>
using namespace std;
char a[105][105];
int ap[105][105];
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
int dp[105][105];
int n,m;
void dfs(int x,int y)
{
    for(int i=0;i<=7;i++)
    {
        int nx=x+dx[i];
        int ny = y+dy[i];
        if(ap[nx][ny]==1&&nx>=1&&nx<=m&&ny>=1&&ny<=n&&dp[nx][ny]==0)
        {
            dp[nx][ny]=1;
            ap[nx][ny]=0;
            dfs(nx,ny);
        }
    }
}
int main()
{
    
    while(1)
    {
        memset(ap,0,sizeof(ap));
        scanf("%d%d",&m,&n);
        if(n==0&&m==0)break;
        for(int i=1;i<=m;i++)
        { 
           
            gets(a[i]);
            for(int j=1;j<=n;j++)
            {
                if(a[i][j]=='@')
                {
                    ap[i][j]=1;
                }
            }
            
        }
        memset(dp,0,sizeof(dp));
        int cnt =0;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(ap[i][j]==1)
                {
                    ap[i][j]=0;
                    dp[i][j]=1;
                    dfs(i,j);
                    cnt+=1;
                }
            }
        }
        printf("%d",cnt);
    }
    return 0;
}