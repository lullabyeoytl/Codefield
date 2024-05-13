#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;//少加载几个库可以省空间，打rk可以用
struct hh
{
	int l,r,id;//存每个询问的l,r和排序前的位置
	long long len;//区间大小
}b[60000];
int a[60000],bl[60000],n,m,blo,num[60000];
long long ans1[60000],ans2[60000],tot;
//常用卡常技巧:inline把函数展开减少调用，register把变量放到CPU寄存器
//还有快读和快写都是不用说的，以及位运算代替普通运算
//但最重要的是降低你算法的复杂度，比如fft板子的rk1用基4-fft虐rk2一百ms
//当然不是我，我就是不相信为什么那么快就把人家的代码粘过来并开了O2(逃
//但我可是这题的rk1啊踩了chenzhe大爷16ms的（逃
inline bool cmp(const hh &a,const hh &b)//排序的规则
{
	if(bl[a.l]<bl[b.l])return 1;
	if(bl[a.l]>bl[b.l])return 0;
	if(bl[a.l]&1)return a.r<b.r;//按奇偶块分别排，减少块切换所用代价
	return a.r>b.r;
//return bl[a.l]^bl[b.l]?bl[a.l]<bl[b.l]:bl[a.l]&1?a.r<b.r:b.r>b.r;
}
inline char gc()//用fread把读入加速到极致，具体我也不懂，背板子就好
{
	static char BB[1000000],*S=BB,*T=BB;
	return S==T&&(T=(S=BB)+fread(BB,1,1000000,stdin),S==T)?EOF:*S++;
}
inline int getin()//getchar换成fread的快读
{
	register int x=0;register char ch=gc();
	while(ch<48)ch=gc();
	while(ch>=48)x=x*10+(ch^48),ch=gc();
	return x;
}
inline void add(int x){tot+=((num[x]<<1)|1),num[x]++;}//添加操作
//(num[x]<<1)|1就是num[x]*2+1,因为<<1之后二进制最后一位为0，可以按位或
inline void rem(int x){tot+=1-(num[x]<<1),num[x]--;}//删除操作
int wt[30];//快写所用数组
inline void putout(long long x)
{
	if(!x){putchar(48);return;}//putchar要比普通输出快，不知道有没有像fread一样的东西
	register int l=0;          
	while(x)wt[++l]=x%10,x/=10;
	while(l)putchar(wt[l--]+48);
    //可以写递归版，如下:
    //if(x>9)putout(x/10);putchar(x%10+48);效率差不多
}
int main()
{
	n=getin(),m=getin();
	register int blo=n/sqrt((m>>1)/3);//blo块大,根据lxl所说这样能快10%
	for(register int i=1;i<=n;i++)a[i]=getin();
	for(register int i=1;i<=m;i++)b[i].l=getin(),b[i].r=getin(),b[i].len=b[i].r-b[i].l+1,b[i].id=i,ans2[i]=1,bl[i]=(i-1)/blo+1;
	sort(b+1,b+m+1,cmp);//排序
	register int l=b[1].l,r=b[1].r;
	for(register int i=l;i<=r;i++)add(a[i]);//先把l[1]-r[1]加进去
	register long long fz,fm,g;
	if(tot!=b[1].len)//防爆，就是l==r,不然你过不了样例，下同
	{
		fz=tot-b[1].len,fm=b[1].len*(b[1].len-1),g=__gcd(fz,fm);
		ans1[b[1].id]=fz/g,ans2[b[1].id]=fm/g;//约分
        //貌似开O2的话自带的gcd比手写能快一点
	}
	for(register int i=2;i<=m;i++)
	{
		while(l<b[i].l)rem(a[l++]);//l小了就删
		while(l>b[i].l)add(a[--l]);//l大了就加
		while(r>b[i].r)rem(a[r--]);//r大了就删
		while(r<b[i].r)add(a[++r]);//r小了就加
		if(b[i].len!=tot)
		{
			fz=tot-b[i].len,fm=b[i].len*(b[i].len-1);
			g=__gcd(fz,fm),ans1[b[i].id]=fz/g,ans2[b[i].id]=fm/g;
		}
	}
    //当然你也可以不开ans1和ans2，但那样要重新排序回来
	for(register int i=1;i<=m;i++)putout(ans1[i]),putchar('/'),putout(ans2[i]),putchar(10);
}