#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m;
int dp[1001][1001];
int a[1001][1001];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
    {
        dp[1][i]=a[i][1];
    }
	for(int i=2;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
            int temp=dp[i-1][j];
            if(j>1)
            {
                temp=max(temp,dp[i-1][j+1]);
            }
            if(j<n)
            {
                temp=max(temp,dp[i-1][j-1]);
            }
            dp[i][j]=temp;
		}
	} 
	printf("%d",dp[n][m]);
    system("pause");
	return 0;
}