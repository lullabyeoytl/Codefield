#include <iostream>
#include <cstring> 
#define INF 0x3f3f3f
using namespace std;
int N;
int f[52][52];
string a;
int main()
{
	cin>>a;
	N = a.size();
    memset(f,INF,sizeof(f));
	for(int i = 1;i <= N;i++){
		f[i][i] = 1;
	}
	for(int len = 2; len <= N; len++){
		for(int i = 1; i <= N - len + 1; i++){
			int head = i, tail = i + len - 1;
			if(a[head-1] == a[tail-1]){
					f[head][tail]=min(f[head + 1][tail],f[head][tail-1]);
					continue;
			}
			for(int k = head; k <= tail; k++){
				f[head][tail]=min(f[head][k] + f[k+1][tail],f[head][tail]);
			}
		}
	}
	cout<<f[1][N];
} 