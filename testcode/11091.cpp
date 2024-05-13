#include <bits/stdc++.h>
using namespace std;
int dp[105][105];
int ti[105],zi[105];
int main()
{
    memset(dp,127,sizeof(dp));
   for(int i=0;i<=105;i++)
   {
    dp[i][0]=0;
   }
    int n,k,d,s;
    scanf("%d%d%d%d",&n,&k,&d,&s);
    int cont=0;
    for(int i=1;i<=k;i++)
    {
        scanf("%d%d",&ti[i],&zi[i]);
        if(ti[cont]<=s)
        {
            cont+=1;
        }
    }//1-cont有效
    for(int ko=1;ko<=cont;ko++)
    {
        for(int j=1;j<=n;j++)
        {
            int temp[5];
            memset(temp,127,sizeof(temp));
            temp[0]=dp[ko-1][j];
            for(int df=1;df<=zi[ko];df++)
            {
                if(j>=df)
                temp[df]=dp[ko-1][j-df]+df*ti[ko]+d;
            }
            sort(temp,temp+zi[ko]+1);
            dp[ko][j]=temp[0];
        }
    }
    if(dp[k][n]>=10000)cout<<"impossible";
    else
    printf("%d",dp[cont][n]);
    system("pause");
    return 0;
}
