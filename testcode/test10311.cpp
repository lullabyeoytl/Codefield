#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[55];
int b[55];
int dp[10005];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        scanf("%d",&b[i]);
    }
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(dp[j]>=0)
            {
                dp[j]=b[i];
            }
            else if(j<a[i]||dp[j-a[i]]<=0)
            {
                dp[j]=-1;
            }
            else
            {
                dp[j]=dp[j-a[i]]-1;
            }
        }
    }
    if(dp[m]>=0)printf("Yes\n");
    else 
    printf("No\n");
    system("pause");
    return 0;

}