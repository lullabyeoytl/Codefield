#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
unsigned long long res = 18446744073709551615;
long long a[15],b[15];
int n;
long long minn( long long a, long long b)
{
    if(a<=b)
    return a;
    else
    return b;
}
void dfs(int i,int x,int y)
{
    if(i>n)
    {
        if(x==1&&y==0)return ;
        res = minn((long long)abs(x-y),res);
        return ;
    }
    dfs(i+1,x*a[i],y+b[i]);
    dfs(i+1,x,y);
    //不存在重复调用就无需记忆化
}
int main()
{
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
        scanf("%lld%lld",&a[i],&b[i]);
    }
    dfs(1,1,0);
    printf("%lld\n",res);
    return 0;
}