#include<bits/stdc++.h>
#define ll long long 
using namespace std;
#define p 1000000007
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
	return s*w;
}
inline int qpow(ll a,int b){
	int ans=1;
	a=(a%p+p)%p;
	for(;b;b>>=1){
		if(b&1) ans=(a*ans)%p;
		a=(a*a)%p;
	}
	return ans%p;
}
ll w,n,k;
int main(){
	w=read(),n=read(),k=read();
	int ans=w*qpow(qpow(2,k),p-2)%p;
	ans%=p;
	printf("%lld",ans);
	return 0;
}