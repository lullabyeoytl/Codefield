/*
#include <bits/stdc++.h>
using namespace std;
int linum[2505],lisun[1005];
int cmin[1005],cmax[1005];
int dp[1005][1005];
int main()
{
    int c,l;
    scanf("%d%d",&c,&l);
    int minn=1001,maxn=-1;
    for(int i=1;i<=c;i++)
    {
        scanf("%d%d",&cmin[i],&cmax[i]);
        minn=min(minn,cmin[i]);
        maxn=max(maxn,cmax[i]);
    }
    for(int i=1;i<=l;i++)
    {
        scanf("%d%d",&lisun[i],&linum[i]);
        dp[lisun[i]][lisun[i]]=linum[i];
    }
    for(int len=minn;len<=maxn;len++)
    {
        for(int i=min;i<=max-len+1;i++)
        {
            j=;en+i-1;

        }
    }
    system("pause");
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
int ans;
struct cow{
    int l;
    int r;
} 
ox[5000];
struct sunscreen{
    int n;
    int s;
} 
suns[5000];
bool com(struct cow x,struct cow y)
{
    {
        if(x.r<y.r) return true;
        return false;
        }
}
bool comp(struct sunscreen a,struct sunscreen b)
{
    if(a.n<b.n)
    return true;
    return false;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    scanf("%d %d",&ox[i].l,&ox[i].r);
    for(int i=1;i<=m;i++)
    scanf("%d %d",&suns[i].n,&suns[i].s);
    sort(ox+1,ox+1+n,com);
    sort(suns+1,suns+m+1,comp);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        if(suns[j].n>=ox[i].l&&suns[j].n<=ox[i].r&&suns[j].s)
        {
            suns[j].s--;ans++;
            break;
        }
    }
    printf("%d",ans);
    system("pause");
    return 0;
}
