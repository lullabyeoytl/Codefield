/*
#include <bits/stdc++.h>
using namespace std;
int n;long long m;
int k[300],c[300];
int lnn[11]={0,0,69,110,139,161,179,195,208,220,230};
int dp[100005];
int main()
{
    memset(dp,0x3f,sizeof(dp));
    scanf("%d%lld",&n,&m);
    m=(int)100*log(m)+1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&k[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&c[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=m+1;j>=0;j++)
        {
            for(int kr=1;kr<=k[i];kr++)
            {
              if(j>=lnn[kr])
             {
               dp[j]=min(dp[j],dp[j-lnn[kr]]+kr*c[i]);
              }
            }
        }
    }
    printf("%d",dp[m+1]);
    system("pause");
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;
int n;long long m;
int k[300],c[300];
int lnn[11]={0,0,69,110,139,161,179,195,208,220,230};
int dp[300][100005];
int minest(int a,int b,int c)
{
    int s1=min(a,b);
    return min(s1,c);
}
int main()
{
   
    memset(dp,127,sizeof(dp));
     dp[0][0]=0;
    scanf("%d%lld",&n,&m);
    m=(int)100*log(m)+1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&k[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&c[i]);
        for(int kr=1;kr<=k[i];kr++)
        dp[i][lnn[kr]]=c[i]*kr;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            for(int kr=1;kr<=k[i];kr++)
            dp[i][j]=minest(dp[i][j],dp[i-1][j],dp[i-1][j-lnn[kr]]+c[i]*kr);
        }
    }
    printf("%d",dp[n][m]);
    system("pause");
    return 0;
}


