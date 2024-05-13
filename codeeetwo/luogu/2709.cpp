#include <bits/stdc++.h>
using namespace std;
#define maxn 50001
#define ll long long
#define fo(x,y) for(register int i=x;i<=y;++i)
ll ans[maxn],c;
int a[maxn],b[maxn],n,m,k,bl;
struct node{
	int l,r,id;
}modui[maxn];

inline bool cmp(node x,node y){
	if((x.l-1)/bl==(y.l-1)/bl) return x.r<y.r;
	return x.l/bl<y.l/bl;
}

inline int read(){
	int x=0,fh=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') fh=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*fh;
}
inline void add(int x){
	c+=2*b[x]+1;
	b[x]++;
}
inline void del(int x){
	c-=2*b[x]-1;
	b[x]--;
}
int main(){
	int lef,rig,ans1=1,ans2=0;
	n=read(),m=read(),k=read();
	bl=sqrt(n);
	fo(1,n){
		a[i]=read();
	}
	fo(1,m){
		modui[i].l=read();
		modui[i].r=read();
		modui[i].id=i;
	}
	sort(modui+1,modui+1+m,cmp);
	fo(1,m){
		lef=modui[i].l,rig=modui[i].r;
		while(ans1>lef) ans1--,add(a[ans1]);
		while(ans2<rig) ans2++,add(a[ans2]);
		while(ans1<lef) del(a[ans1]),ans1++;
		while(ans2>rig) del(a[ans2]),ans2--;
		ans[modui[i].id]=c;
	}
	fo(1,m) printf("%lld\n",ans[i]);
	return 0;
}
