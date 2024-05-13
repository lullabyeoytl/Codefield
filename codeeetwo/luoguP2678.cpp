#include<cstdio>
#include<algorithm>
using namespace std;
int i,L,N,M,a[50005];

int check(int d){
	int i,last=0,cnt=0;
	for(i=1;i<=N;i++){
		if(a[i]-last<d)cnt++;
		else last=a[i];
	}
	if(L-last<d)cnt++;
	return cnt<=M;
}
 
int main(){
	scanf("%d %d %d",&L,&N,&M);
	for(i=1;i<=N;i++)scanf("%d",a+i);
	sort(a+1,a+1+N);
	int lo=1,hi=L+1,mid;
	while(lo+1<hi){
		mid=(lo+hi)/2;
		if(check(mid))lo=mid;
		else hi=mid;
	}
	printf("%d\n",lo);
    return 0;
}