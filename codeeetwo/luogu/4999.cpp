#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define Pi 1000000007
ll f[30][15],a[30],power[30];
int ask(ll x) 
{
	int w=0,ans=0;
	while(x) 
	{
		a[++w]=x%10;
		x/=10;
	}
	for(int i=1;i<w;i++)
		for(int j=1;j<=9;j++) 
        ans+=f[i][j],ans%=Pi; 
	for(int i=1;i<a[w];i++) 
    ans+=f[w][i],ans%=Pi;
	int sum=a[w]; 
	for(int i=w-1;i>=1;i--)
	{
		ans+=sum*power[i-1]*a[i]%Pi;
		ans%=Pi;
		for(int j=0;j<a[i];j++)
			ans+=f[i][j],ans%=Pi; 
		sum+=a[i]; 
	}
	return ans;
}

int main()
{
	for(int i=0;i<=9;i++) 
    f[1][i]=i;
	power[0]=1;
	for(int i=1;i<=18;i++) 
    power[i]=power[i-1]*10%Pi; 
	for(int i=2;i<=18;i++) 
    {
		for(int j=0;j<=9;j++)
		{
			f[i][j]=j*power[i-1]%Pi;
			for(int k=0;k<=9;k++)
				f[i][j]+=f[i-1][k],f[i][j]%=Pi; 
		}
    }
	int T;
    scanf("%d",&T);
	while(T--)
	{
		ll x,y;
        scanf("%lld%lld",&x,&y);
        printf("%d",((ask(y+1)-ask(x))%Pi+Pi)%Pi);
	}
	return 0;
}