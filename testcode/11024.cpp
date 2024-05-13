#include <bits/stdc++.h>
using namespace std;
int n, ans = 0;
int rowmax[207];
int a[207][207];
int dp[207][207][2];
int main() 
{
    scanf("%d",&n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n + i - 1; j++) 
        {
			scanf("%d",&a[i][j]);
			rowmax[i] = max(rowmax[i], a[i][j]);
		}
	for(int i = 1; i <= n - 1; i++)
		for(int j = 1; j <= 2 * n - i - 1; j++)
         {
		    scanf("%d",& a[i + n][j]) ;
			rowmax[i + n] = max(rowmax[i + n], a[i + n][j]);
		}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n + i - 1; j++) {
			dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j - 1][0]) + a[i][j];
			dp[i][j][1] = max(max(dp[i - 1][j][1], dp[i - 1][j - 1][1]) + a[i][j], max(dp[i - 1][j][0], dp[i - 1][j - 1][0]) + rowmax[i]);
		}
	for(int i = 1; i <= n - 1; i++)
		for(int j = 1; j <= 2 * n - i - 1; j++) {
			int w = i + n;
			dp[w][j][0] = max(dp[w - 1][j][0], dp[w - 1][j + 1][0]) + a[w][j];
			dp[w][j][1] = max(max(dp[w - 1][j][1], dp[w - 1][j + 1][1]) + a[w][j], max(dp[w - 1][j][0], dp[w - 1][j + 1][0]) + rowmax[w]);
		}
	for(int i = 1; i <= n; i++)
		ans = max(ans, dp[n * 2 - 1][i][1]);
	printf("%d",ans);
	return 0;
}