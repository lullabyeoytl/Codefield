/*
	直接考虑问题比较困难。我们首先考虑另一个问题，如果给定一个距离d，
 问至少要移走多少石头才能满足石头之间的最小距离不小于d？对于这个问题，
 答案就很简单了。我们采取贪心的策略计算：从左岸开始，移走它小于d的所
 有石头，再往后跳一步，循环往复。所以我么将石头按位置排序，在模拟一遍
 跳的过程就可以得到这个问题的答案。
 
 	接下来，有一点是显而易见的，d增大时，需要移走的石头数一定不变或
 更多。直接枚举d的值会很慢，所以我们对这个d进行二分，判断最小距离
 为d时移走的最少石头数是否会超过M块。我们用变量lo记录可行解，用
 hi记录不可行解。每次mid=(lo+hi)/2,检验mid是否可行，可行则
 lo=mid，不可行则hi=mid，直到lo+1与hi相等时停止，lo就是最后答
    案。就这样，整个问题就被成功解决了。时间复杂度为O(nlog2L)。
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define M(a) memset(a,127,sizeof a)
#define fo(j,n) for(i=j;i<=n;i++)
using namespace std;
int i,L,N,M,a[50010];

int check(int dist){//检验函数，求出给定距离dist后 需要移走多少石头，是否不超过M 
	int i,last=0,cnt=0;
	for(i=1;i<=N;i++){
		if(a[i]-last<dist)cnt++;
		else last=a[i];
	}
	if(L-last<dist)cnt++;
	return cnt<=M;
}
 
int main(){
	scanf("%d %d %d",&L,&N,&M);
	for(i=1;i<=N;i++)scanf("%d",a+i);
	sort(a+1,a+1+N);
	int lo=1,hi=L+1,mid;
	while(lo+1<hi){//二分查找模板 
		mid=(lo+hi)/2;
		if(check(mid))lo=mid;
		else hi=mid;
	}
	printf("%d\n",lo);
}