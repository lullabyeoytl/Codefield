#include <bits/stdc++.h>
using namespace std;
int dp[15][10];
int a[15];
int b[15];
int main()
{
    int n;
    scanf("%d",&n);
    int s=0;int temp=n;int tep2=n;
    while(temp>0)
    {
        s++;
        a[s]=temp%10;
        temp/=10;
    }//1-s
    for(int i=s;i>=1;i--)
    {
        tep2-=pow(10,i-1)*a[i];
        b[i]=tep2;
    }
    for(int i=1;i<=s;i++)
    {

    }
    dp[1][1]=1;
    for(int len=2;len<=s;len++)
    {
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<=9;j++)
                {
                    dp[len][i]+=dp[len-1][j];
                }
            if(i==1)
            {
                dp[len][i]+=pow(10,len-1);
            }

        }
    }
    long long ans=0;
    for(int i=s;i>=1;i--)
    {
        for(int j=0;j<=a[i]-1;j++)
        {
            ans+=dp[i][j];
        }
        if(a[i]==1)
        {
            ans+=b[i];
            ans++;
        }
        
    }
    printf("%lld\n",ans);
    system("pause");
    return 0;
}
