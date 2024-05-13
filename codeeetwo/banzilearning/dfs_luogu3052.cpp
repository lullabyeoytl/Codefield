/*
#include <bits/stdc++.h>
using namespace std;
int n,w;
int we[20];
int dp[20];
int cnt;
int minn=100000;
int mid;
//关注的装态量为正在装的组数，现有体积，上一个w的编号,已装的物体数
int dfs(int group , int vi,int sum)
{
    if(group>mid)
    {
        return -1;
    }
    if(sum==n)
    {
        minn=min(minn,group);
        return minn;
    }
    for(int i=group;i<=n;i++)
    {
        if(dp[i]==1)continue;
        else
        {
            if(vi+we[i]>w)
            {
                dp[i]=1;
                dfs(group+1,we[i],sum+1);
                dp[i]=0;//回溯
            }
            else
            {
                dp[i]=1;
                dfs(group,vi+we[i],sum+1);
                dp[i]=0;
            }
        }
    }
    return minn;
}
int main()
{
    scanf("%d%d",&n,&w);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&we[i]);
    }
    memset(dp,0,sizeof(dp));
   int res= dfs(1,0,0);
    printf("%d",res);
    system("pause");
    return 0;
}
*/
#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, c[19], tot(0), ans(0), v[19];
bool dfs(int x, int num){//x为奶牛号， num为车厢数
    for (int i = 1; i <= x && i <= num; ++i)//for车厢号，看奶牛能被放进哪个车厢
        if(v[i] + c[x] <= m){
            v[i] += c[x];
            if(x == n) return 1;
            if(dfs(x+1, num)) return 1;
            v[i] -= c[x];
        }
    return 0;//全部搜过一遍，不行；
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &c[i]);
    int lo=1; int hi= n;
    while(lo<hi)
    {
        int mid=(lo+hi)/2;
        fill(v+1, v+n+1, 0);
        if(dfs(1,mid)==1)hi=mid;
        else lo=mid+1;
    }
    printf("%d\n",lo);
   system("pause");
    return 0;
}