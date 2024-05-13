#include <cstdio>
#include <algorithm>
using namespace std;
struct Edge{
    int pi,qi,ri;
    bool operator > (const Edge b)
    {
        return this->ri>b.ri;
    }
}edge[100000];
struct QUERY{
    int id ,ki,vi;
    bool operator >(const QUERY b)
    {
        return this->ki>b.ki;
    }
}query[100005];
int ans[100005];
bool cmp1(struct Edge a, struct Edge b)
{
    return a.ri>b.ri;
}
bool cmp2(struct QUERY a,struct QUERY b)
{
    return a.ki>b.ki;
}
int fa[100005],siz[100005];
int get(int x)
{
    if(fa[x]==x)return x;
    else
    return fa[x]=get(fa[x]);
}
void emerge(int x,int y)
{
    if(x==y)return;
 fa[y] =  x;
 siz[x]+=siz[y];
}
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d%d",&edge[i].pi,&edge[i].qi,&edge[i].ri);
        fa[i]=i;siz[i]=1;
    }
    fa[n]=n;siz[n]=1;
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d",&query[i].ki,&query[i].vi);
        query[i].id=i;
    }
    sort(edge+1,edge+n,cmp1);
    sort(query+1,query+q+1,cmp2);
    int pos=1;
    for(int i=1;i<=q;i++)
    {
        for( ;edge[pos].ri>=query[i].ki&&pos<n;pos++)
        {
            emerge(get(edge[pos].pi),get(edge[pos].qi));
        }
        ans[query[i].id]=siz[get(query[i].vi)]-1;
    }
    for(int i=1;i<=q;i++)
    {
        printf("%d\n",ans[i]);
    }
    system("pause");
    return 0;
}
//注意到只有大于k的有贡献，可以按k从高到低逐渐建树，维护siz数组来维持并查集大小
//还是那个按边权分类的最小生成树的思想