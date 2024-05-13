#include<iostream>
#include<cstdio>
using namespace std;
struct node
{
    int y,pt;
}b[50005];
const int low=-0x7fffffff/2;
int n,m,a[100005],t1[400005],t2[400005],fyr=low,len;//a：位置离散化后的原始数组；b：年份->a数组位置转换数组；t1、t2：线段树 
void build(int root,int s,int e)
{
    if (s==e)
    {
        t1[root]=t2[root]=a[s];
        return;
    }
    int mid=(s+e)/2;
    build(root*2,s,mid);
    build(root*2+1,mid+1,e);
    t1[root]=max(t1[root*2],t1[root*2+1]);
    t2[root]=min(t2[root*2],t2[root*2+1]);
}
int mn(int root,int s,int e,int ts,int te)
{
    if (ts>e||te<s)return 0x7fffffff/2;
    if (ts>=s&&te<=e)return t2[root];
    int mid=(ts+te)/2;
    return min(mn(root*2,s,e,ts,mid),mn(root*2+1,s,e,mid+1,te));
}
int mx(int root,int s,int e,int ts,int te)
{
    if (ts>e||te<s)return low;
    if (ts>=s&&te<=e)return t1[root];
    int mid=(ts+te)/2;
    return max(mx(root*2,s,e,ts,mid),mx(root*2+1,s,e,mid+1,te));
}
int reval(int year)//获得年份在线段树数组上的位置 
{
    if (year<b[1].y)return 0;
    if (year>b[n].y)return len+1;
    int l=1,r=n,mid;
    while (l<=r)//二分，注意边界值，mid落在不大于year的位置 
    {
        mid=(l+r)>>1;
        if (b[mid].y<year)l=mid+1;
        else r=mid-1;
    }
    if (b[l].y!=year)return b[l].pt-1;
    return b[l].pt;//如果没有这个年份，就指向空年份 
}
int main()
{
    scanf("%d",&n);
    int year,val;
    for (int i=1;i<=n;i++)//处理年份与位置的转化 
    {
        scanf("%d %d",&year,&val);
        if (fyr==low||year-fyr==1)fyr=year,a[++len]=val;
        else fyr=year,a[++len]=low,a[++len]=val;//不相邻的年份，无论年份之间相隔多少，全部离散化为2 
        b[i].y=year;
        b[i].pt=len;
    }
    a[len+1]=a[0]=low;
    build(1,1,len);
    scanf("%d",&m);
    int x,y,u,v;
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d",&x,&y);
        u=reval(x);
        v=reval(y);
        if (v-u==1)//我不知道有没有这样的坑数据，X,Y相邻…… 
        {
            if (a[u]==low||a[v]==low)printf("maybe\n");
            else if (a[u]>=a[v])printf("true\n");
            else printf("false\n");
        }
        else if ((a[u]!=low&&a[u]<=mx(1,u+1,v-1,1,len))||(a[u]!=low&&a[u]<a[v])||(a[v]!=low&&mx(1,u+1,v-1,1,len)>=a[v]))printf("false\n");//判断false的情况，注意a[u,v]!=0，否则会WA得很惨 
        else if (a[u]==low||a[v]==low||mn(1,u+1,v-1,1,len)==low)printf("maybe\n");//判断可能的情况 
        else printf("true\n");
    }
}
