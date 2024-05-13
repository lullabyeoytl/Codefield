#include <cstdio>
#include <algorithm>
using namespace std;
struct data {int x,y,z;};//结构体便于排序的变换
data f[100005];
int n,m,a[20005],b[20005],i;
inline bool cmp(data a,data b)//重写cmp函数
{
    return a.z>b.z;
}
inline int find(int x)
{
    if(a[x]==x) return x;
    a[x]=find(a[x]);
    return a[x];
}
inline void ad(int x,int y)//合并
{
    x=find(a[x]);
    y=find(a[y]);
    a[x]=y;
}
inline bool check(int x,int y)//查找
{
    x=find(x);
    y=find(y);
    if(x==y) return true;
    return false;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) a[i]=i;
    for(i=1;i<=m;i++)
        scanf("%d%d%d",&f[i].x,&f[i].y,&f[i].z);
    sort(f+1,f+m+1,cmp);//c党的优越感~
    for(i=1;i<=m+1;i++)//为什么m+1呢？如果运行到m+1会输出0，想想为什么。
    {
        if(check(f[i].x,f[i].y)) {printf("%d",f[i].z);break;}//如果两个罪犯已经在同一监狱就输出 ，并退出
        else
        {
            if(!b[f[i].x]) b[f[i].x]=f[i].y;//标记“敌人”
                else {ad(b[f[i].x],f[i].y);}//将敌人的敌人合并
            if(!b[f[i].y]) b[f[i].y]=f[i].x;
                else {ad(b[f[i].y],f[i].x);}
        }
    }
    return 0;
}
/*
思路是按边从大到小来分，但不急着让每对数急着分成两组，而是先互相标记成敌人，唯有“敌人的敌人”出现后方可确定怎么分
*/