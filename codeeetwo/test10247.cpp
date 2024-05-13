#include<cstdio>
using namespace std;
int a[105];
int res=0;
int n,m;
void dfs(int mon,int k)
{
    if(mon>=n+1)
    return;
    else if(mon==0)
    {
        res+=1;
        return;
    }
    if(mon<0)
    return;
    else
    {
    for(int i=0;i<=1;i++)
    {
        dfs(mon-i*a[k],k+1);
    }
    }
    return ;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    dfs(m,1);
    printf("%d",res);
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
const int maxn=10000+10;
int v[maxn],f[maxn];
int main(){
    int n,m;
    cin>>n>>m;
    f[0]=1;
    for(int i=1;i<=n;++i)    
        cin>>v[i];
    for(int i=1;i<=n;++i)
        for(int j=m;j>=v[i];--j)
            f[j]+=f[j-v[i]];
    cout<<f[m]<<endl;
    return 0;
}
*/