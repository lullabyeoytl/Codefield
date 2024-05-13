#include<bits/stdc++.h>
using namespace std;
long long n,m,a[17],f[17][65536],ans;
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
	n=read();m=read();
	for(int i=1;i<=n;i++)
    a[i]=read();
	for(int i=1;i<=n;i++)
    f[i][1<<(i-1)]=1;
	for(int j=1;j<=(1<<n)-1;j++)
	{
		for(long long i=1;i<=n;i++)
		{
			if(!(j&(1<<i-1)))continue;
			for(long long k=1;k<=n;k++)
			{
				if(j&(1<<(k-1)))
                continue;
				if(abs(a[k]-a[i])>m)
                f[k][(1<<(k-1))|j]+=f[i][j];
			}
		}
	}
	for(long long i=1;i<=n;i++)ans+=f[i][(1<<n)-1];
	printf("%lld",ans);
}