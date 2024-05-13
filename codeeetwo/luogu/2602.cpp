#include<iostream>
#include<cstring>
#include<cstdio>
#define re register
#define maxn 14
#define LL long long
LL dp[maxn][10][10];
LL L,R;
LL ans[10][2];
int a[maxn],num;
inline LL quick(LL a,LL b)
{
	LL s=1;
	while(b)
	{
		if(b&1) s*=a;
		b>>=1;
		a*=a;
	}
	return s;
}
inline void slove(LL x,int pd)
{
	memset(dp,0,sizeof(dp));
	num=0;
	memset(a,0,sizeof(a));
	while(x)
	{
		a[++num]=x%10;
		x/=10;
	}
	for(re int i=0;i<=9;i++) dp[1][i][i]=1;
	for(re int i=2;i<=num;i++)
		for(re int j=0;j<=9;j++)
		{
			for(re int k=0;k<=9;k++)
			{
				for(re int p=0;p<=9;p++)
					dp[i][j][p]+=dp[i-1][k][p];
			}
			dp[i][j][j]+=quick(10,i-1);
		}
	for(re int i=1;i<num;i++)
    		for(re int j=1;j<=9;j++)
			for(re int k=0;k<=9;k++)
				ans[k][pd]+=dp[i][j][k];
	for(re int i=1;i<a[num];i++)
		for(re int k=0;k<=9;k++)
			ans[k][pd]+=dp[num][i][k];
	for(re int i=num-1;i>=1;i--)
	{
		for(re int j=0;j<a[i];j++)
		{
			for(re int k=0;k<=9;k++)
				ans[k][pd]+=dp[i][j][k];
		}
		for(re int p=num;p>i;p--)
				ans[a[p]][pd]+=a[i]*quick(10,i-1);
        
	}
    //但是这个dp全程都不能处理出x是否满足条件
    //因为最后也只是判断第一位上的数比给定数的第一位小
    //所以slove(x)其实求得是[0,x)满足条件的数的个数
}
int main()
{
	scanf("%lld%lld",&L,&R);
	slove(R+1,0),slove(L,1);
	for(re int i=0;i<=9;i++)
		printf("%lld ",ans[i][0]-ans[i][1]);
	putchar(10);
	return 0;
}