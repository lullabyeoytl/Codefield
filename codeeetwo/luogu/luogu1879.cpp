#include <bits/stdc++.h>
using namespace std;
int dp[15][2048];
int a[15][15];
#define pi 100000000
int opps(int n,int t)
{
    return (2<<n)-1-t;
}
int check(int t)
{
    if(t>=1)
    {
        while(t>0)
        {
            while(t%2==0)
            {
                t>>2;
            }
             if(t%4==3)
            {
              return 0;
            }
             else
             t-=1;
        }
        return 1;
    }
    if(t==0)
    {
        return 1;
    }
}
int check2(int i,int t,int n)
{
    for(int j=n;j>=1;j--)
    {
        if(a[i][j]==1)
        {
            t/=2;
            continue;
        }
        
        else
        {
            if(t-2*(t/2)==1)
            {
                return 0;
            }
            else
            {
                t/=2;
            }
        }

    }
    return 1;
}
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<=(2<<n)-1;i++)
    {
        if(check(i)==1&&check2(1,i,n)==1)
        {
            dp[1][i]=1;
        }
        else
        dp[1][i]=0;
    }
    for(int i=2;i<=m;i++)
    {
        for(int j=0;check(j)==1&&j<=(2<<n)-1&&check2(i,j,n)==1;j++)
        {
            int k=opps(n,j);
            for(int l=k;l|k==k&&l>=0&&check(l)==1&&check2(i,l,n)==1;l--)
            {
                dp[i][j]+=dp[i-1][l];
                dp[i][j]%=pi;
            }
        }
    }
    int res=0;
    for(int q=0;check(q)==1&&q<(2<<n)&&check2(m,q,n)==1;q++)
    {
        res+=dp[m][q];
        res%=pi;
    }
    printf("%d",res);
    system("pause");
    return 0;


}