#include <bits/stdc++.h>
using namespace std;
int dp[1005];
int v[55];
int main()
{
    memset(dp,-1,sizeof(dp));
    int n,vobg,vomax;
    scanf("%d%d%d",&n,&vobg,&vomax);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&v[i]);
    }
    dp[vobg]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=vomax;j>=0;j--)
        {
            if(j-v[i]<0)
            {
                if(j+v[i]<=vomax)
                {
                    dp[j]=dp[j+v[i]];
                }
                else
                dp[j]=-1;
            }
            else
            {
                if(j+v[i]<=vomax)
                {
                    dp[j]=max(dp[j-v[i]],dp[j+v[i]]);
                }
                else
                dp[j]=dp[j-v[i]];
            }
        }
    }
    int icheck=0;
    for(int i=vomax;i>=0;i--)
    {
        if(dp[i]==0)
        {
            printf("%d",i);
            icheck=1;
            break;
        }
    }
    if(icheck==0)
    {
        printf("-1\n");
    }
    system("pause");
    return 0;
}
