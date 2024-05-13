#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
__int128 dp[10001];

void write(__int128 x)
{
    if(x>9) write(x/10);//如果x>9的话就递归它的最高位，再往下依次输出 
    putchar(x%10+'0');//输出这个数的末尾/kk（+'0'是为了让它转成字符类型的 
}
int main()
{
	int n,k;
	cin>>n>>k;
	dp[0]=1;//初始化！让n为0时的方案数为1 
	for(int i=1;i<=k;i++)//枚举每一个物品 
	{
		for(int j=i;j<=n;j++)//必须大于i，否则买不了/kk 
		{
			dp[j]+=dp[j-i];//那么这个方案数就是上面所推导的一坨 
		}
	}
	write(dp[n]);//要用__int128否则会炸longlong（ull也好像不行 
	return 0;
}