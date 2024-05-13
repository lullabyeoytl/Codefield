#include <bits/stdc++.h>
using namespace std;
long long minn(long long a, long long b)
{
    if(a<b)
    return a;
    else
    return b;
}
long long minest(long long a,long long b,long long c)
{
   long long s1= minn(a,b);
   return minn(s1,c);
    
}
int n;
long long c[1001];
int ai[1001];
int bi[1001];
int ci[1001];
long long dp[1001][2][2][2];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=1;j++)
        {
           for(int k=0;k<=1;k++)
           {
            for(int l=0;l<=1;l++)
            {
                dp[i][j][k][l]=922337203685477580;
            }
           }
        }
    }
    for(int i=1;i<=n;i++)
    {
        string a;
        cin>>c[i]>>a;
        if(a.find('A')!=string::npos)
        {
            ai[i]=1;
        }
        if(a.find('B')!=string::npos)
        {
            bi[i]=1;
        }
        if(a.find('C')!=string::npos)
        {
            ci[i]=1;
        }

        dp[i][ai[i]][bi[i]][ci[i]] = c[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=1;j++)
        {
            for(int k=0;k<=1;k++)
            {
                for(int l=0;l<=1;l++)
                {
                    if(j==0&&k==0&&l==0)
                    dp[i+1][j][k][l]=minest(dp[i+1][j][k][l],dp[i][j][k][l],dp[i][0][0][0]);
                    else if(j==0&&k==0&&l!=0)
                    dp[i+1][j][k][l]=minest(dp[i+1][j][k][l],dp[i][j][k][l],dp[i][j][k][l-ci[i+1]]+c[i+1]);
                    else if(j==0&&k!=0&&l==0)
                    dp[i+1][j][k][l]=minest(dp[i+1][j][k][l],dp[i][j][k][l],dp[i][j][k-bi[i+1]][l]+c[i+1]);
                    else if(j!=0&&k==0&&l==0)
                    dp[i+1][j][k][l]=minest(dp[i+1][j][k][l],dp[i][j][k][l],dp[i][j-ai[i+1]][k][l]+c[i+1]);
                    else if(j!=0&&k!=0&&l==0)
                    dp[i+1][j][k][l]=minest(dp[i+1][j][k][l],dp[i][j][k][l],dp[i][j-ai[i+1]][k-bi[i+1]][l]+c[i+1]);
                    else if(j==0&&k!=0&&l!=0)
                    dp[i+1][j][k][l]=minest(dp[i+1][j][k][l],dp[i][j][k][l],dp[i][j][k-bi[i+1]][l-ci[i+1]]+c[i+1]);
                    else if(j!=0&&k==0&&l!=0)
                    dp[i+1][j][k][l]=minest(dp[i+1][j][k][l],dp[i][j][k][l],dp[i][j-ai[i+1]][k][l-ci[i+1]]+c[i+1]);
                    else if(j!=0&&k!=0&&l!=0)
                    {
                        dp[i+1][j][k][l]=minest(dp[i+1][j][k][l],dp[i][j][k][l],dp[i][j-ai[i+1]][k-bi[i+1]][l-ci[i+1]]+c[i+1]);
                    }
                }
            }
        }

    }   
    if(dp[n+1][1][1][1]==922337203685477580)printf("-1");
    else
    printf("%lld",dp[n+1][1][1][1]);
    system("pause");
    return 0;
 
}