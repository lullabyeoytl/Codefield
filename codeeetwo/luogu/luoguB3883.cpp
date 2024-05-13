#include <bits/stdc++.h>
using namespace std;
int dp[105][10];
char n[105];
int a[105];
#define pi 20091119
int main()
{
    scanf("%s",n);
    for(int i=0;i<strlen(n);i++)
    {
        a[i]=n[i]-48;
    }
    for(int i=1;i<=2;i++)
    {
        for(int j=0;j<=9;j++)
        dp[i][j]=1;
    }
    for(int i=3;i<=strlen(n);i++)
    {
        for(int j=0;j<=9;j++)
        {
            for(int k=0;k<=9;k++)
            dp[i][j]+=dp[i-2][k];
            dp[i][j]%=pi;
        }
    }
    int ans=0;
    for(int i=1;i<=strlen(n)-1;i++)
    {
        for(int k=1;k<=9;k++)
        {
            ans+=dp[i][k];
            ans%=pi;
        }
    }
    if(strlen(n)%2==0)
    {
        int t=strlen(n)/2;
        for(int i=0;i<=t-1;i++)
        {
            if(i==0)
            {
                for(int j=1;j<=a[i]-1;j++)
                {
                    ans+=dp[strlen(n)-2*i][j];
                    ans%=pi;
                }
            }
            else
            {
                for(int j=0;j<=a[i]-1;j++)
                {
                    ans+=dp[strlen(n)-2*i][j];
                    ans%=pi;
                }
            }
        }
        int cnt=1;
        while(a[t-cnt]==a[t+cnt-1])
        {
            cnt++;
        }
        if(a[t-cnt]<a[t+cnt-1])
        {
            ans+=1;
            ans%=pi;
        }
    }
    else
    {
        int t=strlen(n)/2;
        for(int i=0;i<=t;i++)
        {
            if(i==0)
            {
                for(int j=1;j<=a[i]-1;j++)
                {
                    ans+=dp[strlen(n)-2*i][j];
                    ans%=pi;
                }
            }
            else
            {
                for(int j=0;j<=a[i]-1;j++)
                {
                    ans+=dp[strlen(n)-2*i][j];
                    ans%=pi;
                }
            }
        }
        int cnt=1;
        while(a[t-cnt]==a[t+cnt])
        {
            cnt++;
        }
        if(a[t-cnt]<a[t+cnt])
        {
            ans+=1;
            ans%=pi;
        }
        

    }
    ans%=pi;
    printf("%d",ans);
    system("pause");
    return 0;


}