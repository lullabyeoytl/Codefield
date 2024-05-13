#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
int n;
struct node{int x,y;}a[50005];
bool cmp(node x,node y){return x.y<y.y;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d %d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
	int t=a[1].y,ans=1;
	for(int i=2;i<=n;i++)if(a[i].x>=t){t=a[i].y;ans++;}
	printf("%d",ans);
	return 0;
}