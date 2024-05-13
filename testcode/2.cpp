#include <bits/stdc++.h>
using namespace std;
int a[2005],v[2005];
bool dp[500005];
inline int read()
{
    int x=0;int f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
    return x*f;
}
int main()
{
	int T,n,m,mx,cnt,tmp;
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		int atemp,vtemp;
		atemp=read(),vtemp=read();
		for(int j=1;vtemp-j>=0;j*=2)
		{
			a[++cnt]=j*atemp;
			vtemp-=j;
		}
		if(vtemp>0) a[++cnt]=vtemp*atemp;
	}
	dp[0]=true;
	for(int i=1;i<=cnt;i++)
	{
		while(dp[tmp]&&tmp<=mx) tmp++;
		if(tmp>=mx) break;
		int nd=max(tmp,a[i]);
		for( int j=mx;j>=nd;j--)
			if(dp[j-a[i]]) dp[j]=true;
	}
	for( int i=1;i<=m;i++)
	{
		int ti=read();
		if(dp[ti]) 
		printf("Yes\n");
		else printf("No\n");
	}
    system("pause");
	return 0;
}
