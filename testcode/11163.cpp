#include <bits/stdc++.h>
using namespace std;
string str;
int a[1010];
int s2[1010];
int s3[1010];
int s4[1010];
int dp[1010][1010];
int ti[1010][1010];
int main()
{
    getline(cin,str);
    int cnt = str.find('=');
    int res=0;int dig=0;
    for(int i=str.size()-1;i>=cnt+1;i--)
    {
        res+=pow(10,dig)*(str[i]-48);
        dig++;
    }
    for(int i=0;i<=cnt-1;i++)
    {
        a[i]=str[i]-48;
    }
    for(int i=0;i<=cnt-1;i++)
    {
        dp[i][i]=a[i];
    }
    for(int i =0;i<=cnt-2;i++)
    {
        s2[i]=10*a[i]+a[i+1];
        s3[i]=100*a[i]+10*a[i+1]+a[i+2];
        s4[i]=1000*a[i]+100*a[i+1]+10*a[i+2]+a[i+3];
    }
      for(int len=2;len<=cnt;len++)
    {
        for(int i=0;i<=cnt-len;i++)
        {
            int j=i+len-1;
            if(j==2)
            {
                int temp=s2[i];
                if(temp<res)
                dp[i][j]=temp;
                int dig=i;int k;
            for( k=i;k<=j-1;k++)
            {
                if(dp[i][k]+dp[i+1][j]<res)
                {
                    dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
                    if(dp[i][k]+dp[k+1][j]>dp[i][j])dig=k;
                }
            }
            if(dp[i][j]>temp)
            {
                ti[i][j]=ti[i][k]+ti[k+1][j]+1;
            }
            }
            if(j==3)
            {
                int temp=s3[i];
                if(temp<res)
                dp[i][j]=temp;
                int dig=i;int k;
            for(k=i;k<=j-1;k++)
            {
                if(dp[i][k]+dp[i+1][j]<res)
                {
                    dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
                    if(dp[i][k]+dp[k+1][j]>dp[i][j])dig=k;
                }
            }
            if(dp[i][j]>temp)
            {
                ti[i][j]=ti[i][k]+ti[k+1][j]+1;
            }
            }
            if(j==4)
            {
                int temp=s4[i];
                if(temp<res)
                dp[i][j]=temp;int k;
            for( k=i;k<=j-1;k++)
            {
                if(dp[i][k]+dp[k+1][j]<res)
                {
                    dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
                    if(dp[i][k]+dp[k+1][j]>dp[i][j])dig=k;
                }
            }
            if(dp[i][j]>temp)
            {
                ti[i][j]=ti[i][k]+ti[k+1][j]+1;
            }
            }
            else
            {
                int k;
            for( k=i;k<=j-1;k++)
            {
                if(dp[i][k]+dp[k+1][j]<res)
                {
                    dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
                    if(dp[i][k]+dp[k+1][j]>dp[i][j])dig=k;
                }
                ti[i][j]=ti[i][k]+ti[k+1][j]+1;
            }
            }
           
        }
    }
    printf("%d",ti[0][cnt-1]);
    system("pause");
    return 0;
}