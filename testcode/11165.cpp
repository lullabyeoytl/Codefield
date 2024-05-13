#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000; 

char A[1010]; 
int B; 
int pre[1010], dp[5010][5010]; 
int n; 

int tran(int now, int sum)
{
	if(now == n)
    return sum == 0 ? 0 : INF;
	int &str = dp[now][sum]; 
	if(str != -1){
		return str;
	}
	str = INF;
	int temp = 0;
	for(int j = pre[now]; j < n; j++){
		temp = temp * 10 + A[j] - '0'; 
		if(temp > sum) break;
		int hip = tran(j + 1, sum - temp);
		str = str < hip + 1 ? str : hip + 1; 
	}
	return str;
}

int solve(int now, int sum){ 
	if(now == n){
		printf("=%d\n", B);
		return 1;
	}
	if(now > 0)printf("+");
	int num = 0;
	for(int j = now;j < n; j++){
		printf("%c", A[j]);
		num = num * 10 + A[j] - '0';
		if(tran(now, sum) == 1 + tran( j + 1, sum - num)){
			return solve(j + 1, sum - num);
		}
	}
	return 0;
}

int main()
{
	char c = getchar();
	while(isdigit(c)){
		A[n++] = c;
		c = getchar();
	}
	scanf("%d", &B);
	n = strlen(A);
	pre[n-1] = n - 1;
	for(int i = n - 2; i >= 0; i--){
		pre[i] = (A[i] == '0') ? pre[i + 1] : i;
	}
	memset(dp, -1, sizeof(dp)); 
	solve(0, B);
    system("pause");
	return 0;
}