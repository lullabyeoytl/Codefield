#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	int l,r,pos;
}t[2000010];
int last1[2000010],last2[2000010],c[2000010],a[2000010],ans[2000010];
int n,q,m;
inline bool cmp(node A,node B){
   return A.r<B.r;
}
inline void add(int x,int val){
    for(int i=x;i<=n;i+=(i&-i))c[i]+=val;
}
inline int query(int x){
    int ans=0;
    for(int i=x;i;i-=(i&-i))
    ans+=c[i];
    return ans;
}
int main(){
    scanf("%d%d%d",&n,&q,&m);
    for(int i=1;i<=n;++i)
    scanf("%d",&a[i]);
    for(int i=1;i<=m;++i){
       scanf("%d%d",&t[i].l,&t[i].r);
       t[i].pos=i;
    }
    sort(t+1,t+m+1,cmp);
    int j=1;
    for(int i=1;i<=m;++i){
    	for(;j<=t[i].r;++j){
           if(!last1[a[j]])last1[a[j]]=j;
           else {
           	  if(!last2[a[j]]){
           	  	add(last1[a[j]],1);
                last2[a[j]]=j;
           	  }else {
           	  	 add(last2[a[j]],1);
           	  	 add(last1[a[j]],-1);
           	  	 last1[a[j]]=last2[a[j]];
           	  	 last2[a[j]]=j;
           	  } 
           }
    	}
    	ans[t[i].pos]=query(t[i].r)-query(t[i].l-1);
    }
    for(int i=1;i<=m;++i)
    printf("%d\n",ans[i]);
    return 0;
}
/*
 回顾hh的项链，我们使用离线+树状数组，
 和last[j]表示上一次出现j的位置，对于第p个的数j,我们add(last[j],-1),add(p,1),
 !因为我们按照r从小到大排序依次对经过了的点处理，只有r>的点才有效，才会去处理
 ，只用管最右边的一个，所以留下最右端的就可以，对于一个询问直接树状数组求区间和；
 比较一下这两道题的区别，同样是计算颜色不同的数量，但是这道题目要求只有存在两个相同颜色这个颜色才做出贡献，怎么办呢？
 我们维护两个东西，last1[j]表示上上次出现j的位置,last2[j]表示上次出现的位置
 对于第p个的数j
 第一次出现j时没有用，我们直接记录last1=p;
 第二次出现j时，他就会产生代价，但值得注意的是我们不应该在第二次出现j的为位置上+1，
 而是在上一次出现的位置last1上+1，这是因为我们按照r从小到大排序,比如2,2,3这个序列，
 如果我们在第二次出现2的位置上+1，变成(0,1,0)，当询问[2,3]就不对了,应该在倒数第二次出现的位置+1变成(1,0,0);
 !这里注意到根本不会询问到last1前面的区间，询问按r大小分类已经在last1时解决了。
 两次以上出现，我们只需要在倒数第2次的位置上+1，其他位置上出现j全部为零，
 实现：add(last1[j],-1);add(last2[j],1),last1=last2,last2=j;
 !因为我们只关心离得最近的
 扩展：如果将题目的限制改一改变成有n个颜色同时在询问区间，我们我们可以仍按照r递增排序，
 维护last1,last2,~~,lastn;让倒数第n次的位置上+1,其他出现j的位置上全是0
*/