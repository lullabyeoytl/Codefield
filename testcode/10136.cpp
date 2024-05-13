#include <bits/stdc++.h>
using namespace std;
int n,m;
int dp[10004][501];
int di[10004];
int maxn=-1;
void dfs(int check, int p, int dist,int imin)
{
    if(imin==n+1)
    {
        if(p==0)
        maxn=max(maxn,dist);
        else
        return ;
    }
    else
    {
        if(check==1)
        {
            if(p+1<=m)
            {
                dfs(1,p+1,dist+di[imin],imin+1);
                dfs(0,p-1,dist,imin+1);
            }
            if(p+1>m)
            {
                dfs(0,p-1,dist,imin+1);
            }
        }
        if(check==0)
        {
            if(p==0)
            {
                dfs(0,p,dist,imin+1);
                dfs(1,p+1,dist+di[imin],imin+1);
            }
            else
            {
                dfs(0,p-1,dist,imin+1);
                dfs(1,p+1,dist+di[imin],imin+1);
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&di[i]);
    }
    dfs(1,0,0,1);
    printf("%d",maxn);
    
    system("pause");
    return 0;
    
}