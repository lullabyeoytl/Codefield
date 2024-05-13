#include <bits/stdc++.h>
using namespace std;
int a[5][150005];
int s[5][120005];
int dp[150005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            s[i][j]=s[i][j-1]+a[i][j];
        }
    }
    int minn[10];
    for(int lit=1;lit<=6;lit++)
    {
        if(lit==1)
        {
            dp[2]=a[1][1]+a[2][2]+s[3][n]-s[3][2];
            minn[1]=dp[2];
            for(int i=3;i<=n-1;i++)
            {
               dp[i]=min(dp[i-1]+a[2][i]-a[3][i],s[1][i-1]+a[2][i]+s[3][n]-s[3][i]);
               minn[1]=min(minn[1],dp[i]);
            }
        }
        if(lit==2)
        {
            dp[2]=a[1][1]+a[3][2]+s[2][n]-s[2][2];
            minn[2]=dp[2];
            for(int i=3;i<=n-1;i++)
            {
               dp[i]=min(dp[i-1]+a[3][i]-a[2][i],s[1][i-1]+a[3][i]+s[2][n]-s[2][i]);
               minn[2]=min(minn[2],dp[i]);
            }
        }
        if(lit==3)
        {
            dp[2]=a[2][1]+a[1][2]+s[3][n]-s[3][2];
            minn[3]=dp[2];
            for(int i=3;i<=n-1;i++)
            {
               dp[i]=min(dp[i-1]+a[1][i]-a[3][i],s[2][i-1]+a[1][i]+s[3][n]-s[3][i]);
               minn[3]=min(minn[3],dp[i]);
            }
        }
        if(lit==4)
        {
            dp[2]=a[2][1]+a[3][2]+s[1][n]-s[1][2];
            minn[4]=dp[2];
            for(int i=3;i<=n-1;i++)
            {
               dp[i]=min(dp[i-1]+a[3][i]-a[1][i],s[2][i-1]+a[3][i]+s[1][n]-s[1][i]);
               minn[4]=min(minn[4],dp[i]);
            }
        }
        if(lit==5)
        {
            dp[2]=a[3][1]+a[1][2]+s[2][n]-s[2][2];
            minn[5]=dp[2];
            for(int i=3;i<=n-1;i++)
            {
               dp[i]=min(dp[i-1]+a[1][i]-a[2][i],s[3][i-1]+a[1][i]+s[2][n]-s[2][i]);
               minn[5]=min(minn[5],dp[i]);
            }
        }
         if(lit==6)
        {
            dp[2]=a[3][1]+a[2][2]+s[1][n]-s[1][2];
            minn[6]=dp[2];
            for(int i=3;i<=n-1;i++)
            {
               dp[i]=min(dp[i-1]+a[2][i]-a[1][i],s[3][i-1]+a[2][i]+s[1][n]-s[1][i]);
               minn[6]=min(minn[6],dp[i]);
            }
        }
        
    }
     int minres;
    for(int lo=1;lo<=6;lo++)
    {
         minres=min(minn[1],minn[2]);
         minres=min(minres,minn[3]);
         minres=min(minres,minn[4]);
         minres=min(minres,minn[5]);
         minres=min(minres,minn[6]);

    }
    printf("%d",minres);
    system("pause");
    return 0;
    
}