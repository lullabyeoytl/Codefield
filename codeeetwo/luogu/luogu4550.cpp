#include <cstdio>
#include <cstdlib>
double dp[10001][100000];
int main()
{
    int n;
    scanf("%d",&n);
    dp[1][1]=1.0;
    for(int i=2;i<=n-1;i++)
    {
        dp[1][i]=((double)1/double(n))*dp[1][i-1];
        dp[i][i]=dp[i-1][i-1]*(1-(double)(i-1)/(double)n);
    }
    for(int i=3;i<=10*n-1;i++)
    {
        for(int j=2;j<=n-1;j++)
        {
            dp[j][i]=j*dp[j][i-1]+(n-j+1)*dp[j-1][i-1];
            dp[j][i]/=(double)n; 
        }
    }
    long double ans=0;
    for(int i=n-1;i<=10*n;i++)
    {
        ans+=dp[n-1][i]*(i+1);
    }
    ans/=double(n);
    printf("%.2Lf",ans);
    system("pause");
    return 0;
}