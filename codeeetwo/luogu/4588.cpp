#include <bits/stdc++.h>
using namespace std;

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

struct segmenttree
{
    int l,r;
    int muti;
}t[400005];

void build(int p,int l,int r,int m)
{
    t[p].l=l;t[p].r=r;
    if(l==r)
    {
        t[p].muti=1;
        return ;
    }
    int mid=(l+r)/2;
    build(p*2,l,mid,m);
    build(p*2+1,mid+1,r,m);
    t[p].muti=t[2*p].muti*t[2*p+1].muti;
    t[p].muti%=m;
}

void change(int p,int x,int v,int m)
{
    if(t[p].l==t[p].r)
    {
        t[p].muti=v;
        return;
    }
    int mid=(t[p].l+t[p].r)/2;
    if(x<=mid)change(p*2,x,v,m);
    else change(p*2+1,x,v,m);
    t[p].muti=t[2*p].muti * t[2*p+1].muti;
    t[p].muti%=m;
}

int ask(int p,int l,int r)
{
    if(l<=t[p].l && r>=t[p].r)
    return t[p].muti;
    int val=1;
    int mid = (t[p].l+t[p].r)/2;
    if(l<=mid)val*=ask(p*2,l,r);
    if(r>mid)
    val*=ask(2*p+1,l,r);
    return val;
}

int main()
{
    int t=read();
    for(int i=1;i<=t;i++)
    {
       int q=read(),m=read();
       build(1,1,q,m);
       for(int j=1;j<=q;j++)
       {
           int op=read(),dig=read();
           if(op==1)
           {
            change(1,j,dig,m);
            if(i==t&&j==q)printf("%d",ask(1,1,q));
            else
            printf("%d\n",ask(1,1,q));
           }
           if(op==2)
           {
            change(1,dig,1,m);
            if(i==t&&j==q)printf("%d",ask(1,1,q));
            else
            printf("%d\n",ask(1,1,q));
           }
       }
    }
    system("pause");
    return 0;

}