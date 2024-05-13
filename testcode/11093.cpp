#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int pi=998244353;
const int N=1e6+2,inv2=pi+1>>1;
int t,n,i,j,x;
int mi[N],mii[N];
int cal(int x)
{
	return (ll)(mi[x]+mii[x])*inv2%pi;
}
int main()
{
	mi[0]=mii[0]=1;
	for (i=1;i<N;i++) mi[i]=(ll)mi[i-1]*10%pi,mii[i]=(ll)mii[i-1]*8%pi;
	scanf("%d",&t);
	while (t--)
	{
        scanf("%d%d",&n,&x);
		printf("%d\n",n==1?9:(cal(n)-cal(n-1)+pi)%pi);
	}
    system("pause");
    return 0;
}