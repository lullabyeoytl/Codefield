#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int f[270000][66],a[270000];
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        f[i][a[i]]=i+1;
    }
    for (int j=2;j<=60;j++)
        for (int i=1;i<=n;i++){
            if (f[i][j]==0) f[i][j]=f[f[i][j-1]][j-1];
            if (f[i][j]>0) ans=max(ans,j);
        }
    printf("%d\n",ans);
    return 0;
}
/*不妨设一个f[i][j]表示到第i个数，得到数值为j，向右合并的最右端点。

方程f[i][j]=f[f[i][j-1]][j-1];*/