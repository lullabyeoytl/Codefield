#include <bits/stdc++.h>
using namespace std;
int k[2050],a[2050];
int v[500000];
int dp[5000000];
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
        x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int main()
{
    int n,m;
    n=read();m=read();
    int numt=1;


    for(int i=1;i<=n;i++)
    {
        k[i]=read();a[i]=read();int atemp=a[i];
        for(int j=1;atemp-j>=0;j*=2)
        {
            v[numt]=j*k[i];
            numt++;
            atemp-=j;
        }
        if(atemp)
        {
        v[numt]=atemp*k[i];
        numt++;  
        } 
    }

    dp[0]=1;dp[v[1]]=1;
   for(int i=2;i<=numt-1;i++)
   {
        dp[v[i]]=1;
       for(int j=500000;j>=v[i];j--)
       {
           dp[j]=max(dp[j],dp[j-v[i]]*dp[v[i]]);
       }
   }
   for(int i=1;i<=m;i++)
   {
        int t=read();
        if(dp[t])printf("Yes\n");
        else
        printf("No\n");
   }
    system("pause");
    return 0;
}