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
const int size=200005;
struct segmenttree
 {
    int l,r;
    long long sum,add;
    #define l(x) tree[x].l
    #define r(x) tree[x].r
    #define sum(x) tree[x].sum
    #define add(x) tree[x].add   //lazy tag:表示该节点曾经被修改但其子节点尚未被更新
 }tree[4*size];
 int a[size],n,m;
  //建树
 void build(int p,int l ,int r)
 {
    l(p)=l,r(p)=r;
    if(l==r)
    {
        sum(p)=a[l];
        return ;
    }
    int mid=(l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    sum(p) = sum(p*2)+sum(p*2+1);
 }
  //下实现延迟标记向下传递
  void spread(int p)
  {
    if(add(p))//!节点p有标记
    {
        sum(p*2)+=add(p)*(r(p*2)-l(p*2)+1);//!更新左子节点信息,若父节点有标记，则没必要递归到子节点，让子节点全部加d就OK，然后让标记下延重复操作
        sum(p*2+1)+=add(p)*(r(p*2+1)-l(p*2+1)+1);//!更新右子节点信息
        add(p*2)+=add(p);//给左节点打标记
        add(p*2+1)+=add(p);//给右节点打标记
        add(p) = 0;//!清除p标记（此时其子节点也完成修改）,保证标记只在第一个包含地方打
    }
  }
  //进行区间修改
  void change(int p, int l, int r, int d)
  {
    if(l<=l(p)&&r>=r(p))//见;azy tag笔记中对应的完全覆盖情况
    {
        sum(p)+=(long long)d * (r(p)-l(p)+1);
        add(p)+=d;
        return;
    }
    spread(p); //下传延时标记
    int mid = (l(p)+r(p))/2;
    if(l<=mid)change (p*2,l,r,d);
    if(r>mid)change(p*2+1,l,r,d);
    sum(p) = sum(p*2)+sum(p*2+1);
  }
  //进行区间查询
  long long ask(int p,int l,int r)
  {
    if(l<=l(p)&&r>=r(p))return sum(p);
    spread(p); //下传延时标记
    //!ask里也必须要有spread不然无法对节点信息更新：
    //!!注意lazy tag修改的只是根节点的信息
    int mid = (l(p)+r(p))/2;
    long long val = 0;
    if(l<=mid) val+=ask(p*2,l,r);
    if(r>mid)val += ask(p*2+1,l,r);
    return val;
  }
  int main(){
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    build(1,1,n);
    m=read();
    for(int i=1;i<=m;i++){
        int op=read();
        if(op==3){
            int iq=read();
            printf("%d\n",ask(1,iq,iq));
        }
        if(op==1){
            int iq=read();
            change(1,1,n,iq);
        }
        if(op==2){
            int xq=read(),iq=read();
            change(1,xq,xq,ask(1,xq,xq)+iq);
        }
    }
  }
