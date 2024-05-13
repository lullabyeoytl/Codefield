#include <bits/stdc++.h>
using namespace std;
int n,m;
struct segtree
{
    int l,r;
    long long dat;
    int add;//lazy tag,要加什么
}t[2000006];
int a[500005];

void build(int p,int l,int r)
{
    t[p].l=l;t[p].r=r;
    if(l==r)
    {
        t[p].dat=a[l];
        return ;
    }
    else
    {
        int mid=(l+r)/2;
        build(2*p,l,mid);
        build(2*p+1,mid+1,r);
        t[p].dat=t[2*p].dat+t[2*p+1].dat;
    }
}

void spread(int p)
{
    if(t[p].add)
    {
        t[2*p].dat+=t[p].add*(t[2*p].r-t[2*p].l+1);
        t[2*p+1].dat+=t[p].add*(t[2*p+1].r-t[2*p+1].l+1);
        t[2*p].add+=t[p].add;
        t[2*p+1].add+=t[p].add;
        t[p].add=0;
    }
}

void change(int p,int l,int r,int d)
{
    if(l<=t[p].l&&r>=t[p].r)
    {
        t[p].dat+=(long long )d* (t[p].r-t[p].l+1);
        t[p].add+=d;//后续递归调用会发现会限制第一个满足条件的才有标记
        return ;
    }
    spread(p);
    int mid = (t[p].l+t[p].r)/2;
    if(l<=mid)change(p*2,l,r,d);
    if(r>=mid+1)change(p*2+1,l,r,d);
    t[p].dat=t[2*p].dat+t[2*p+1].dat;
}

long long ask(int p,int l,int r)
{
    if(l<=t[p].l&&r>=t[p].r)
    return t[p].dat;
    else
    {
        spread(p);
        int mid=(t[p].l+t[p].r)/2;
        long long val=0;
        if(l<=mid)val+=ask(p*2,l,r);
        if(r>mid)val+=ask(p*2+1,l,r);
        return val;
    }
}

inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
        x=x*10+ch-'0',ch=getchar();
    return x*f;
}

int main()
{
    n=read();m=read();
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
    }


    build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        int op;
        op=read();
        if(op==1)
        {
            int x,y,k;
            x=read();y=read();k=read();
            change(1,x,y,k);
        }
        if(op==2)
        {
            int x;
            x=read();
            long long ans=ask(1,1,x)-ask(1,1,x-1);
            printf("%lld\n",ans);
        }
    }
    system("pause");
    return 0;
}
