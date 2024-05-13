#include <bits/stdc++.h>
using namespace std;
int fa[1003];
struct Mess
{
    int li;int ri;int ti;
    bool operator <(const Mess b){
  return this->ti < b.ti;
 }
}mess[100005];
int get(int x)
 {
    if(fa[x]==x)return x;
    return fa[x]=get(fa[x]);
 }
int check(int n)
{
    int flag=get(1);
    for(int i=2;i<=n;i++)
    {
        if(get(i)!=flag)
        {
            return 0;
        }
        else
        continue;
    }
    return 1;
}

int erge(int x,int y)
{
    fa[get(x)] = get(y);
    return 0;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&mess[i].li,&mess[i].ri,&mess[i].ti);
    }
    sort(mess+1,mess+m+1);
    for(int i=1;i<=m;i++)
    {
        erge(mess[i].li,mess[i].ri);
        if(check(n))
        {
            printf("%d",mess[i].ti);
            system("pause");
            return 0;
        }

    }
    printf("-1");
    system("pause");
    return 0;


}
/*
按边权排序：最小生成树
*/