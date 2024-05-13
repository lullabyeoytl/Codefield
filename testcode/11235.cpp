#include <bits/stdc++.h>
using namespace std;
#define pi 998244353
 long long qkpow(long long a,long long p,long long mod)
 {
	 long long t=1,tt=a%mod;
	 while(p)
	 {
		 if(p&1)t=t*tt%mod;
		 tt=tt*tt%mod;
		 p>>=1;
	 }
	 return t;
 }
 long long getInv(long long a,long long mod)
 {
	 return qkpow(a,mod-2,mod);
 }

long long a[2001],b[2001];
long long s1[2001],s2[2001];

inline long long read()
{
    long long x=0,f=1;
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
    long long n=read();long long m=read();
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
        s1[i]=s1[i-1]+a[i];
    }
    for(int j=1;j<=m;j++)
    {
        b[j]=read();
        s2[j]=s2[j-1]+b[j];
    }
    priority_queue<long long> q1;
    priority_queue<long long> q2;
    for(int i=0;i<=n-1;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            q1.push(s1[j]-s1[i]);
        }
    }
    for(int i=0;i<=m-1;i++)
    {
        for(int j=i+1;j<=m;j++)
        {
            q2.push(s2[j]-s2[i]);
        }
    }
    int  p=0;
    while(!q1.empty()&&!q2.empty())
    {
        long long to1=q1.top();
        long long to2=q2.top();
        if(to1>to2)
        {
            p+=q2.size();
            q1.pop();
        }
        if(to1<=to2)
        {
            q2.pop();
        }
        p%=pi;
    }
    long long q = ((n+1)*n*(m+1)*m/4)%pi;
    long long res = (p*getInv(q,pi))%pi;
    printf("%lld",res);
    system("pause");
    return 0;
}