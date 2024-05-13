#include <bits/stdc++.h>
using namespace std;
int n,m,k,p[505],b[505],dp[505][505];
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=0;i<=m;i++)
		cin>>b[i];
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			for(int l=0;l<=j;l++){
				dp[i][j]=max(dp[i-1][l]+b[p[i]+j-l],dp[i][j]);
			}
		}
	}
	printf("%d",dp[n][k]);
    system("pause");
	return 0;
}