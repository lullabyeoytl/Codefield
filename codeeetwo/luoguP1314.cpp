//显然是二分，但有涉及多次查询某区间检验值的和，
//要用前缀和简化，（用数组记忆化后调用降低时间复杂度）
#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
int w[maxn],v[maxn],l[maxn],r[maxn];
long long pre_n[maxn],pre_v[maxn];
long long Y,s,sum;
int n,m,mx=-1,mn=2147483647;
bool check(int W)
{	
	Y=0,sum=0;
	memset(pre_n,0,sizeof(pre_n));
	memset(pre_v,0,sizeof(pre_v));
	for(int i=1;i<=n;i++)
	{
		if(w[i]>=W) pre_n[i]=pre_n[i-1]+1,pre_v[i]=pre_v[i-1]+v[i];
		else pre_n[i]=pre_n[i-1],pre_v[i]=pre_v[i-1];
	}
	for(int i=1;i<=m;i++)
		Y+=(pre_n[r[i]]-pre_n[l[i]-1])*(pre_v[r[i]]-pre_v[l[i]-1]);
		

	sum=llabs(Y-s);
	if(Y>s) return true;
	else return false;
	
}
int main(){
//	freopen("qc.in","r",stdin);
//	freopen("qc.out","w",stdout); 
	scanf("%d %d %lld",&n,&m,&s); 
	for(int i=1;i<=n;i++)
	{
		scanf(" %d %d",&w[i],&v[i]);
		mx=max(mx,w[i]);
		mn=min(mn,w[i]);	
	}
	for(int i=1;i<=m;i++)
		scanf(" %d %d",&l[i],&r[i]);
	int left=mn-1,right=mx+2,mid;  //这里有的人说要特判左右端点的check，但是其实你把left开成mn-1,right开成mx+2(注意取mx+1时即为W比所有都大，Y是0，这个情况要考虑，所以+2包含mx+1)就可以包含左右端点的check了，会简单点。
	long long ans=0x3f3f3f3f3f3f3f3f;//ll 范围内的无穷大，近似于(maxll/2)的大小
	while(left<=right)
	{
		mid=(left+right)>>1;
		if(check(mid)) 	left=mid+1;
		else right=mid-1;
		if(sum<ans) ans=sum;
	}
	printf("%lld",ans);
	return 0;
} 