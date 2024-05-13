//poj2823
#include<cstdio>
#include<deque>
using std::deque;
const int N=1e6+3;
int a[N];
deque<int> q1,q2;
int main()
{
	int n,k;scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		while(!q1.empty()&&a[q1.back()]>a[i])q1.pop_back();
		q1.push_back(i);
		if(!q1.empty()&&q1.front()<i-k+1)q1.pop_front();
		if(i>=k)printf("%d%c",a[q1.front()],i==n?'\n':' ');
	}//维护一个单增队列，找寻最小值，
	for(int i=1;i<=n;i++)
	{
		while(!q2.empty()&&a[q2.back()]<a[i])q2.pop_back();
		q2.push_back(i);
		if(!q2.empty()&&q2.front()<i-k+1)q2.pop_front();
		if(i>=k)printf("%d%c",a[q2.front()],i==n?'\n':' ');
	}
}