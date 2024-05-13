#include <bits/stdc++.h>
using namespace std;
double dp[2000006];
double a[25][25];
int icheck(int t)
{
    int cnt=0;
    while(t>0)
    {
        t-=t&(-t);
        cnt+=1;
    }
    return cnt;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int temp;
            scanf("%d",&temp);
            a[i][j]=(double)temp/100.0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        dp[1<<(n-i)]=a[1][i];
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=((1<<i)-1); j< (1<<n); j++)
        {
            if( icheck(j)!=i)
            continue;
            else
            {
            int dig[25]={0};int cnt=n;
            int jtemp=j;
            while(jtemp>0)
            {
                if(jtemp%2==1)
                dig[cnt]=1;
                jtemp/=2;
                cnt--;
            }
            for(int k=1;k<=n;k++)
            {
                if(dig[k]!=1)
                continue;
                else
                {
                  if(dp[j]>dp[j-(1<<(n-k))]*a[i][k])
                   {
                    continue;
                    }
                   else
                    dp[j]=dp[j-(1<<(n-k))]*a[i][k];
                }
            }
            }
        }
    }
    printf("%lf",100*dp[(1<<n)-1]);
    system("pause");
    return 0;
}