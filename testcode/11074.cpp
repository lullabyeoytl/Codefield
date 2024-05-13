#include <bits/stdc++.h>
using namespace std;
#define pi 1000000007
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

long long zuhe(long a,long b)
{
    long long sum1=1;
    for(int i=a;i>=a-b+1;i--)
    {
      sum1 = (sum1*i)%pi;
 
    }
    long long sum2=1;
    for(int i=b;i>=1;i--)
    {
        if(abs(i%pi)>abs((i%pi-pi)))
        {
            sum2 =(sum2*(i%pi-pi))%pi;
        }
        else
        {
            sum2 = (sum2*i)%pi;
        }

    }long long i=0;
   
    return (getInv(sum2,pi)*sum1)%pi;
}
int main()
{
    long long d,t,m;
    scanf("%lld%lld%lld",&d,&t,&m);
    if(abs(t/2-m)>abs(t/2-d-m)||m>t)
    printf("0");
    else
    printf("%lld",(zuhe(t,t-m)-zuhe(t,d+m))%pi);
    system("pause");
    return 0;
}
