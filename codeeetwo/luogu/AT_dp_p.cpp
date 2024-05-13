#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N=1e5+5,M=1e9+7;
inline int read(){
	int an=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-f;c=getchar();
	}while(c>='0'&&c<='9'){
		an=an*10+c-'0';c=getchar();
	}return an*f;
}
long long dp[N][2],ans;//1表示黑，0表示白。注意开long long！
vector<int>edge[N];//用vector存邻接表。
void DFS(int a,int pre){
	int siz=edge[a].size();
	dp[a][0]=dp[a][1]=1;
	register int i,y;
	for(i=0;i<siz;++i){//枚举每一棵子树。
		y=edge[a][i];
		if(y==pre)continue;
		DFS(y,a);
		dp[a][0]=(dp[a][0]*(dp[y][0]+dp[y][1]))%M;
		dp[a][1]=(dp[a][1]*dp[y][0])%M;
	}
	return;
}
int main(){
	int n=read();register int i,x,y;
	for(i=1;i<n;++i){//有n-1条边。
		x=read();y=read();
		edge[x].push_back(y);
		edge[y].push_back(x);  
	}
	DFS(1,-1);//默认1为树根，没有父亲。
	ans=(dp[1][0]+dp[1][1])%M;
	printf("%lld\n",ans);
	return 0;
}