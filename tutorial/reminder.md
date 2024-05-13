<font face="楷体">

# *pragma GCC optimize(2)c++手动开启o2优化*；
<br>

# 快读1：
```cpp
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
```
然后main函数里读就这样写
```cpp
d = read();
```

# 重载运算符

使用结构体但涉及比较或演算：要重载运算符；因为没有定义过node的运算。

要重载运算符,如下格式：
```cpp
struct node{
 int x,y;
 node(int x=2,int y=2):x(x),y(y){
 }
 node operator + (const node b) const{
  node c;
  c.x = this->x + b.x;
  c.y = this->y + b.y;
  return c;
 }
 node operator - (const node b) const{
  node c;
  c.x = this->x - b.x;
  c.y = this->y - b.y;
  return c;
 }
 node operator * (const node b) const{
  node c;
  c.x = this->x * b.x;
  c.y = this->y * b.y;
  return c;
 }
 node operator / (const node b) const{
  node c;
  c.x = this->x / b.x;
  c.y = this->y / b.y;
  return c;
 }
};
```
比较运算符：注意以上内容加减比较法则均是自己定义，比如洛谷题解P1309可以先比较
```cpp
if(t.s!=s)return s>t.s;//s是结构体中一元
return idx<t.idx

struct node{
 int x;
 bool operator <(const node b){
  return this->x < b.x;
 }
 bool operator >(const node b){
  return this->x > b.x;
 }
};
int main(){
 node a,b;
 a.x=2,b.x=3;
 printf("%d",b>a);
} 
```
## merge
```cpp
 merge(v1.begin(), v1.end(), v2.begin(),v2.end(), v3.begin());
 ``` 
 v:vector自己定义，可以是结构体，可以是栈，队……

勿忘重载运算符。
<br>

# 字典树trie

初始化根节点1，按多叉树形式与字典序方式排，各节点编号按出现顺序排列
```cpp
int trie[size][26]// trie[i][j]指编号为i的（自然总数有size个）j子节点的编号
int tot = 1;//tot为目前节点数，初始化为一
//插入：
void insert(char*str)//插入str
{
    int len = strlen(str),p=1//p指下一步要操作的编号，初始化为1
    for(int k=0;k<=len-1;k++)
    {
        int ch = str[k]-'a';
        if(trie[p][ch]==0)//如果编号为p的节点无ch这一儿子
        {
            trie[p][ch]=++tot//tot节点数加一，新节点第++tot个出现编号为此
        }
        p=trie[p][ch];//以这个儿子的编号更新编号，继续操作
    }
    end[p] = true;//表示该节点结尾是个单词
}
//查询操作；
bool search(char*str)
{
    int len = strlen(str)-1;p=1//p=1只从根节点开始查
    for(int k =0;k<len;k++)
    {
        p=trie[p][str[k]-'a'];//更新节点
        if(p==0) return false//等于零说明没编号
    }
    return end[p] ; //到了最后一个，end[p]是true表示为一个单词
}
```
# 单调队列应用之*slidingWindows*
```python 
description：An array of size n ≤ 106 is given to you.

There is a sliding window of size k which is moving from the very

left of the array to the very right. You can only see the k numbers in the window. 

Each time the sliding window moves rightwards by one position.

Your task is to determine the maximum and minimum values in the sliding window at each position.
```
```cpp
 #include<stdio.h>
 #include<deque>
 using std::deque;
 const int N=1e6+3;
 int a[N];
 deque<int> q1,q2;
 int main()
 {
	 int n,k;scanf("%d%d",&n,&k);
	 for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	 for(int i=1;i<=n;i++)
	 {
        //找最小，队头表示最小的index
        //当新的元素出现后是“更可能影响”更多windows的元素，先在末尾比较能不能更新
		 while(!q1.empty()&&a[q1.back()]>a[i])q1.pop_back();
		 q1.push_back(i);
         //由windows大小限制，从头更新
		 if(!q1.empty()&&q1.front()<i-k+1)q1.pop_front();
		 if(i>=k)printf("%d%c",a[q1.front()],i==n?'\n':' ');
	 }
	 for(int i=1;i<=n;i++)
	 {
        //找最大
		 while(!q2.empty()&&a[q2.back()]<a[i])q2.pop_back();
		 q2.push_back(i);
		 if(!q2.empty()&&q2.front()<i-k+1)q2.pop_front();
		 if(i>=k)printf("%d%c",a[q2.front()],i==n?'\n':' ');
	 }
 }
 //!维护一个单增队列，找寻最小值
```
# 二叉堆 ,优先队列
 priority_queue<int,vector<int>,greater<int> >q;//这是一个小根堆q

 注意某些编译器在定义一个小根堆的时候```greater <int>``` 和后面的${>}$要隔一个空格，
 
 不然会被编译器识别成位运算符号${>>}$
 
 小根堆显然也可以预处理每一个元素乘以-1然后建立大根堆来实现。

 但优先队列不支持删除堆中任意元素
 
 如果要删除非对顶元素则先标记，若要删除堆顶则删到没有标记为止。
 
 优先队列类型为pair时，当pair的first值相同时，比较second。

# Huffman tree

 Huffman tree构造与Huffman 编码板子：
 ```cpp
 #include<cstdio>
 #include<cstring>
 #include<queue>
 #include<algorithm>
 #define ll long long
 using namespace std;
 struct node
 {
    ll w,h;
    node(){w=0,h=0;}
    node(ll w,ll h):w(w),h(h){}
    bool operator <(const node &a)const{return a.w==w?h>a.h:w>a.w;}
 };//排序原则：如若长度相等，高度小的优先；
 ll ans;
 priority_queue<node>q;
 int main()
 {
    ll n,k;ans=0;scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++)
    {
        ll w;scanf("%lld",&w);
        q.push(node(w,1));//一开始大家都是根节点
    }
    while((q.size()-1)%(k-1)!=0)q.push(node(0,1));//补零使得k-1|n-1
    while(q.size()>=k)
    {
        ll h=-1;ll w=0;
        for(int i=1;i<=k;++i)
        {
            node t=q.top();q.pop();
            h=max(h,t.h);
            w+=t.w;
        }
        ans+=w;
        q.push(node(w,h+1));//把节点权值之和加一起成一个新节点，height+1；
    }
    printf("%lld\n%lld\n",ans,q.top().h-1);
    return 0;
 } 
```
# 位运算，与状态压缩：

 二进制状态压缩：将一个长度为m的bool数组用一个m位二进制整数表示储存：
 
 用位运算查找：
 
 第k位：(n>>k)&1
 
 取出n在二进制表示下第0到k-1位（后k位）：n&((1<<k)-1)
 
 第k位取反：n ^ (1<<k)
 
 对整数n二进制下第k位赋值为1 n|(1<<k)
 
 对整数二进制下第k位赋值为0： n&(~(1<<k))
 
 lowbit(n):定义为非负整数n在二进制表示下“最低位1及其后面所有的0”构成的数值
 
 lowbit(n)实现:先将n取反，此时第k位变为0,第0-k-1位都是1.令n=n+1,进位，第k位变为1，0-k-1位为0
 
 所以lowbit(n) = n&(~n+1)=n&(-n)
 
 用途：配和hash找出整数二进制下所有是一的位，o(1)数量级
 
 只需不断n-=lowbit(n)直至n=0,第几位自然可通过lowbit(n)得知；

# 1ll用法
```cpp
 #include <stdio.h>
 #include <stdlib.h>
 
 int main()
{
    int a = 1LL * 100000 * 100000 / 1000;
    printf("%d", a);
    system("pause");
    return 0;
}
 //否则会溢出；
 ```

# unique( , );
 unique(a,a+t):对数组第零项到第t项去重
 ```cpp
 #include <iostream>
 #include <algorithm>
 int main(void){
    int a[8] = {2, 2, 2, 4, 4, 6, 7, 8};
    int c;
    std::sort(a, a + 8);  //对于无序的数组需要先排序
    c = (std::unique(a, a + 8) - a ); //c表示去重后有多少项；
    std::cout<< "c = " << c << std::endl;
    //打印去重后的数组成员
    for (int i = 0; i < c; i++)
        std::cout<< "a = [" << i << "] = " << a[i] << std::endl;
    return 0;
}
```


# 迭代器
```cpp 
 vector<int> vect;

 vector<int>::iterator  it = vect.begin();
 ```

 首先定义了一个int类型的向量；然后定义了一个具有int元素的迭代器类型。it的类型就是
```cpp vector<int>::iterator```

 迭代器iterator是C++ STL的组件之一，作用是用来遍历容器，而且是通用的遍历容器元素的方式，

 无论容器是基于什么数据结构实现的，尽管不同的数据结构，遍历元素的方式不一样，但是用迭代器遍历不同容器的代码是完全一样的。

 经典的迭代器遍历容器的代码如下：
 vector<int>::iterator it = vec.begin();
 for (; it != vec.end(); ++it)
 {
	 cout << *it << " ";
 }
 cout << endl;


# c++ map
 可以将任何基本类型映射到任何基本类型。如int array[100]事实上就是定义了一个int型到int型的映射。
 
 map提供一对一的数据处理，key-value键值对，其类型可以自己定义，第一个称为关键字，第二个为关键字的值
 
 map内部是自动排序的
 
 ```cpp
 #include<map>头文件
 map<type1name,type2name> maps;//第一个是键的类型，第二个是值的类型
 
 map<string,int> maps;
 
 ```
 map可以使用it->first来访问键，使用it->second访问值
```cpp
 #include<map>
 #include<iostream>
 using namespace std;
 int main()
  {
   map<char,int>maps;
   maps['d']=10;
   maps['e']=20;
   maps['a']=30;
   maps['b']=40;
   maps['c']=50;
   maps['r']=60;
   for(map<char,int>::iterator it=mp.begin();it!=mp.end();it++)
   {
       cout<<it->first<<" "<<it->second<<endl;
   }
   return 0;
 }
  maps.insert() 插入
// 定义一个map对象
 map<int, string> m;
 
  //用insert函数插入pair
 m.insert(pair<int, string>(111, "kk"));
 
// 用insert函数插入value_type数据
 m.insert(map<int, string>::value_type(222, "pp"));
 
// 用数组方式插入
 m[123] = "dd";
 m[456] = "ff";
 maps.begin()返回指向map头部的迭代器
 maps.end()返回指向map末尾的迭代器
  maps.rbegin()返回指向map尾部的逆向迭代器
 maps.rend()返回指向map头部的逆向迭代器
 //反向迭代
 map<string,int>::reverse_iterator it;
 for(it = maps.rbegin(); it != maps.rend(); it++)
    cout<<it->first<<' '<<it->second<<endl;
 maps.empty()判断其是否为空
 maps.swap()交换两个map
  maps:映射即可建立hash表
```
# lower_bound
 lower_bound( begin,end,num)：从数组的begin位置到end-1位置二分查找第一个大于或等于num的数字，
 
 找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。
 
 upper_bound( begin,end,num)：从数组的begin位置到end-1位置二分查找第一个大于num的数字，找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。
 
 时间复杂度:二分的复杂度；
 
  lower_bound( begin,end,num,greater<type>() ):从数组的begin位置到end-1位置二分查找第一个小于或等于num的数字， 找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。
 
 upper_bound( begin,end,num,greater<type>() ):从数组的begin位置到end-1位置二分查找第一个小于num的数字，
 
 找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。

# memset 赋值最大最小值的各种情况集合
 
## int
 "较"的原则：加法不爆。

 极大值：0x7f

 较大值：0x3f

 较小值：0xc0

 极小值：0x80

 ## long long

 "较"的原则：加法不爆。

 极大值：0x7f

 较大值：0x3f

 较小值：0xc0

 极小值：0x80

 ## float

 "较"的原则：保证一定位精度。
 
 7f以上一直到be都是-0 (实际上是一个很小的>-1.0的负数)
 
 极大值：0x7f
 
 较大值：0x4f
 
 较小值：0xce
 
 极小值：0xfe
 
 0xff是 -1.#QNAN0000…… (-∞？)

 ## double
  "较"的原则：保证一定位精度。
 
 极大值：0x7f
 
 较大值：0x43
 
 较小值：0xc2
 
 极小值：0xfe

# 线性dp拾遗：
  !!t0提醒：dp成功的精髓是由最优子结构可以推到最终最优，若最终最优实际上不由最优子结构推出，则不可；
  
  (详见凸优化理论，线性规划属于典型的凸优化问题，具有局部最优即为全局最优的特点)
 
 ## 1.数组由二维降维到一维：
  0/1背包：注意第i次状态只与第i减一次有关：
  那么应该可以让前一个分量只需开0或1就可，每个阶段会不断更新此且有照顾到了相邻两个阶段
  在阶段数大时节省空间。
  ```cpp
  for(int i=1;i<=n;i++)
  {
    for(int j=0;j<=m;j++)
    dp[i&1][j]=dp[(i-1)&1][j];
    for(int j=v[i];j<=m;j++)
    f[i&1][j]=max(f[i&1][j],f[(i-1)&1][j-v[i]]+w[i]);
  }
  int ans =0;
  for(int j=0;j<=m;j++)
  {
    ans = max(ans,f[n&1][j]);
  }
  ```
  !但实际上还进行了一次拷贝：所以应该还可以优化：

 dp[j]:放入j的最大价值和：
```cpp
  int dp[];
  memset(dp,0xcf,sizeof(dp));//-INF;
 dp[0]=0;
 for(int i=1;i<=n;i++)
 for(int j=m;j>=v[i];j--)
 f[j]=max(f[j],f[j-v[i]]+w[i]); //!!为什么是倒叙呢，因为是求最大值，倒叙前面大的部分才是i+1状态可能更新的
//!!另外正序可能会同一个i内多次状态更新，状态相当于用了多次
 int ans=0;
 for(int j=0;j<=m;j++)
  {
    ans = max(ans,f[n&1][j]);
  }
  ```
 !但同时意味这正序正好是完全背包，因为完全背包本来就要在同一个i下更新
  
  完全背包：
  
  dp[j]:放入j的最大价值和：
  ```cpp
  int dp[];
  memset(dp,0xcf,sizeof(dp));//-INF;
 dp[0]=0;
 for(int i=1;i<=n;i++)
 for(int j=v[i];j<=m;j++)
 f[j]=max(f[j],f[j-v[i]]+w[i]);
  int ans=0;
 for(int j=0;j<=m;j++)
  {
    ans = max(ans,f[n&1][j]);
  }
  ```
  
  ## 多重背包及其改进：
  
  ### 二进制拆分：背景每个物品，每个最多选C[i]次:
  
  若看作c[i]个物品效率太低：
  
  令c[i]>=2^0+……+2^p ，c[i]<2^0+……2^(p+1);
  
  把c[i]*v[i]看作
  
  2^0 *v[i],2^1*v[i],……,2^p*v[i],r[i]*v[i],
  
  r[i] = c[i]-2^(p+1)+1;
  
  example:luogu1833
    
  ## 分组背包：n组，每组c[i]个物品，i组j个 v[i][j],价值w[i][j];
  ```cpp
   memset(f,0xcf,sizeof(f));
   f[0]=0;
   for(int i=1;i<=n;i++)
   {
    for(int j=m;j>=0;j++)
    {
        for(int k=1;k<=c[i];k++)
        {
            if(k>=v[i][k])
            f[j]=max(f[j],f[j-v[i][k]]+w[i][k]);
        }
    }
   }
   ```
   
   首先因为是0/1背包，所以j是倒序枚举,此外对c[i]个物品的枚举在j内层
   
   !lyd之提醒：分清阶段（此处第i个），状态（此处j重量），决策（第k个物品选不选），三者枚举由外到内；
   
   example：luogu1064


   ## 区间dp:区间长度作为阶段，区间左右两端描述维度，
   example lydp294 
   
   dp环形结构减少枚举处理：
  
  !任选一个位置断开，复制形成2倍长度的链。
  
  ## 树形dp：DP ON THE TREE
   
   example :lydp300;
   
   采用递归的形式，按结点y分类，dp(y)return y下的最值，
   
   递推：自上而下。
   
   个人以为就是记忆化搜索，即把之前dfs return的内容用dp数组储存即可了;
   
 然后有个二次扫描合根法，remember;

  ### 状态压缩：
  集合的状态区与数对应，可以采用进制，

  ### 数位dp:
  特点：给一些限制条件，求第k小数或区间内有多少满足限制条件的数
    
 ## dp初始化问题
 初始化的细节问题

 我们看到的求最优解的背包问题题目中，事实上有两种不太相同的问法。有的题目要求“恰好装满背包”时的最优解，有的题目则并没有要求必须把背包装满。
 
 一种区别这两种问法的实现方法是在初始化的时候有所不同。
 
 如果是第一种问法，要求恰好装满背包，那么在初始化时除了f[0]为0其它f[1..V]均设为-∞，这样就可以保证最终得到的f[N]是一种恰好装满背包的最优解。
 
 如果并没有要求必须把背包装满，而是只希望价格尽量大，初始化时应该将f[0..V]全部设为0。
 为什么呢？可以这样理解：初始化的f数组事实上就是在没有任何物品可以放入背包时的合法状态。
 
 如果要求背包恰好装满，那么此时只有容量为0的背包可能被价值为0的nothing“恰好装满”，其它容量的背包均没有合法的解，属于未定义的状态，它们的值就都应该是-∞了。
 
 如果背包并非必须被装满，那么任何容量的背包都有一个合法解“什么都不装”，这个解的价值为0，所以初始时状态的值也就全部为0了。
 
 这个小技巧完全可以推广到其它类型的背包问题，后面也就不再对进行状态转移之前的初始化进行讲解。

## 用dp找到背包问题第k优解：
 ```cpp
 for (int i=1;i<=n;i++)   //阶段仍是按每个分类
        for (int j=v;j>=w[i];j--)
        {
            //0/1背包
            int t1=1,t2=1,t[60],len=0;
            //!第k解更新思想：f[m][i]表示v<=m第i好解，其值能由f[m-w[i]][s](s待定)+c[i]与前i-1的f[m][i]而来
            //!那么分别枚举i,s以完成状态更新
            while (t1+t2<=k+1)
            {//!保证len只看前k个（大一点也没毛病？）
              if (f[j][t1]>f[j-w[i]][t2]+c[i]) //!判断第i好的解需不需要更新
               t[++len]=f[j][t1++];//!不需要则保持原状向上更新
               else t[++len]=f[j-w[i]][t2++]+c[i];//!状态开始更新，t2是要更新时才递增
            }
            for (int K=1;K<=k;K++) f[j][K]=t[K];
        }
```
# 并查集：
 储存结构：树，每个集合选择一个固定的元素作为整个集合的代表，树根作为代表
 
 维护fa[x]:保存x的父节点。
 
 操作：
- get:get to know x belongs to which group
- merge: merge group a and group b;

初始化：fa[x]=x;
 
 get的路径压缩：每次查询让访问过的节点都直接指向树根
 ```cpp
 int get(int x)
 {
    if(fa[x]==x)return x;
    return fa[x]=get(fa[x])//向上递归并且让经过的点都与根直接相连
 }
 // merge:
 void merge(int x,int y){
    fa[get(x)] = get(y);
 }
 //若边带权值，可以在路径压缩的同时将其更新为到根的权值之和：
 int get(int x)
 {
    if(x==fa[x])return x;
    int root = get(fa[x]);
    d[x]+=d[fa[x]];//!维护d数组---对边权求和
    return fa[x]= root;//路径压缩
 }
 //merge中维护边权：即边权加上被并入的集合的大小,额外维护一个size数组
 void merge(int x,int y)
 {
    x=get(x),y=get(y);
    fa[x]=y;d[x]=size[y];//!更新父节点与边权
    size[y]+=size[x];//!更新size[]

 }
 ```
 !但如果只关心最大边最小的情形：最小生成树

 !按边权从小到大来建树(Kruskal算法)

 并查集特别适用的地方：可传递的关系中动态维护并查集。

# 树状数组
 定义：c[x]用于保存序列a的区间[x-lowbit(x)+1,x]中所有数的和；
* 支持操作1：求前缀和和
 ```cpp
 int ask(int x)
 {
    int ans=0;
    for(; x; x-=x&-x)//(即x-=lowbit(x))
    {
        ans+=c[x];
    }
    return x;
 }
 ```

* 支持操作2：单点增加
 
 序列中某个a[x]+y只有c[x]及其所有祖先保存的区间和含a[x]，其祖先最多log n个
 ```cpp

 void add(int x,int y)
 {
    for( ; x<=N;x += x&-x)c[x]+=y;
 }
 //!节点x的祖先：x+lowbit(x);
 ```

 树状数组的初始化：
 
 c初始全空，然后对每个x(x从小到大，a[x]在每个要加的地方加一遍）执行add(x,a[x]),NlogN量级

 对于二维也是一样，每一维实际独立，也是记录x-lowbit(x)+1,y与y-lowbit(y)+1,双重循环一下就ok


# 线段树
 定义：
- 1每个节点代表一个区间
- 2有唯一根节点，代表整个统计范围，如[1,N]
- 3每个叶节点代表长为1的元区间[x,x];
- 4每个内部节点[l,r]，左节点是[l,mid],右节点是[mid,r],mid=(l+r)/2;
- 5.编号规则：父子两倍：根节点1，x左子节点为2*x,右子节点2*x+1，最后一行编号可以不连续，保存线段树数组长度要不小于4N.
 ## 建树
 以区间dp中区间最大值为例：
 
 计为dat(l,r),dat(l,r)=max(dat(l,mid),dat(mid+1,r));
 ```cpp
 struct SegmentTree
 {
    int l,r;
    int dat;
 }t[size*4];

 void build (int p,int l,int r)
 {
    t[p].l=l,t[p].r=r;
    if(l==r）
    {
        t[p].dat = a[l];
        return;//叶节点
    }
    int mid=(l+r)/2;
    build(p*2,l,mid);
    build(p*2,mid+1,r);
    t[p].dat = max(t[2*p]).dat,t[2*p+1].dat)//先递归得到t[2*p],t[2*p+1],再得到t[p];
 }
 build(1,1,n);//调用入口
 ```
 ## 修改（单点直接修改）
 单点修改：自下至上修改x为v，从[x,x]开始
 ```cpp
 void change(int p, int x, int v)
 {
    if(t[p].l == t[p].r)
    {
        t[p].dat=v;
        return ;
    }
    int mid = (t[p].l+t[p].r)/2;
    if(x<=mid)change(p*2,x,v);//x在左边
    else change(p*2,x,v)//x在右边，从下到上改，从上到下找
    t[p].dat==max(t[2*p].dat, t[2*p+1].dat);
 }
 change(1,x,v);//调用入口
 ```
 ## 查询

 区间查询：递归过程：
 - 1.若[l,r]完全覆盖当前节点代表的区间，则立即回溯，并且该节点的dat值为候选答案。
 - 2.若左子节点与[l,r]有重叠部分，则递归访问左子节点
 - 3.若右子节点与[l,r]有重叠部分，则递归访问右子节点
 ```cpp 
 int ask(int p,int l,int r)
 {
    if(l<=t[p].l&&r>=t[p].r)return t[p].dat;
    //若完全包含,就直接作为候选答案之一，在后面val=max(val,ask());中更新所需答案
    int mid = (t[p].l+t[p].r)/2;
    int val = -(1<<30);//负无穷大
    if(L<=mid)val=max(val,ask(p*2,l,r));//左有重叠，就找下去
    if(r>mid)val = max(val,ask(p*2+1,l,r));//右有重叠，就找下去
    return val;
    //!图示详见lyd213;
    //!以上操作自己模拟一下时间复杂度就是logN
 }
 cout<<ask(1,1,r)<<endl;
 //!区间最值自此除了用st表，还可以用线段树。
 ```
!!ps: 
此处以询问区间和为例。实际上线段树可以处理很多符合结合律的操作
  
根据需求可在线段树里动态储存许多信息，关键是抓住怎么由2*p与2*p+1状态递推到编号p；
 
## 区间修改：
 
 lazy tag:
 
 比如说修改[l,r],[pr,lr]属于[l,r]但[pr,lr]的父节点也包含于[l,r],
 
 则无须修改[pr,lr],只需修改更大的（才能作为备选）就行。
 
 也就是说除了在修改指令中直接划分成的O(log N)个节点外，任意节点修改延迟到“后续操作中递归到进入父节点时”执行
 
 时间复杂度：O（N）
 
 对区间要改的区间[l,r]中的x,lazy tag所在位置[l1,r1]：树上有标号的最大的含有x且属于[l,r]的区间

 example:把数列中第l-r个数都加d
 ```cpp
 struct segmenttree
 {
    int l,r;
    long long sum,add;
    #define l(x) tree[x].l
    #define r(x) tree[x].r
    #define sum(x) tree[x].sum
    #define add(x) tree[x].add   
    //lazy tag:表示该节点曾经被修改但其子节点尚未被更新
 }tree[4*n];
 int a[n],n,m;
  
  //------------建树----------//
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

  //------下实现延迟标记向下传递-----//
void spread(int p)
  {
    if(add(p))//!节点p有标记
    {
        sum(p*2)+=add(p)*(r(p*2)-l(p*2)+1);
        /**
         * !更新左子节点信息,若父节点有标记，则没必要递归到子节点，让子节点全部加d就OK，然后让标记下延重复操作
         */
        sum(p*2+1)+=add(p)*(r(p*2+1)-l(p*2+1)+1);// 更新右子节点信息
        add(p*2)+=add(p);//给左节点打标记
        add(p*2+1)+=add(p);//给右节点打标记
        add(p) = 0;//!清除p标记（此时其子节点也完成修改）,保证标记只在第一个包含地方打
    }
  }
  
  //--------进行区间修改------------//
  void change(int p, int l, int r, int d)
  {
    if(l<=l(p)&&r>=r(p))//见lazy tag笔记中对应的完全覆盖情况
    {
        sum(p)+=(long long)d * (r(p)-l(p)+1);
        add(p)+=d;
        return;
    }
    spread(p) //下传延时标记
    int mid = (l(p)+r(p))/2;
    if(l<=mid)change (p*2,l,r,d);
    if(r>mid)change(p*2+1,l,r,d);
    sum(p) = sum(p*2)+sum(p*2+1);
  }

  //---------进行区间查询-----------//
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
```
# __int128的使用:
 用途：long long不够但不想开高精度，范围是-2^127到2^127-1,也就是10的39次方左右
 
 __int128在gcc、codeblocks、vs2017都是不被支持的，不过__int128在Linux上可以编译并且能用。
 
 我们提交到大部分OJ上都是可以编译且能用的。
 
 ## 输入输出
 
 C/C++标准IO是不认识__int128这种数据类型的，cin和cout是无法输出__int128的，所以我们要自己实现输入输出，
 
 其他的运算，与int没有什么不同。
 
 可以对long long直接强转成__int128
 
 __int128能直接做加减乘除赋值
 
 输入输出按以下格式：
 ```cpp
 #include <bits/stdc++.h>
 using namespace std;
 inline __int128 read()
{
    __int128 x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
 inline void print(__int128 x)
{
    if(x < 0){
        putchar('-');
        x = -x;
    }
    if(x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
} 
 int main(void)
{
    __int128 a = read();
    __int128 b = read();
    print(a + b);
    cout << endl;
    return 0;
}
```
# 快速幂板子
求a^b%c;
```cpp
 long long mc(long long a, long long b, long long c) 
{
    long long jc=1;
    while(b)
    {
    if(b&1) jc=(jc*a)%c;
    a=(a*a)%c;//a一直更新着a^(2^k)  
    b>>=1;
    }
    return jc;
}
```
 模p的逆元板子：用于分数取模，组合数等等
  1. 利用费马小定理&欧拉定理+快速幂：
 ```cpp
 long long qkpow(long long a,long long p,long long mod)
 {
	 long long t=1,tt=a%mod;
	 while(p)
	 {
		 if(p&1)t=t*tt%mod;
		 tt=tt*tt%mod;
		 p>>=1;
	 }
	 return t;
 }//快速幂
 long long getInv(long long a,long long mod)
 {
	 return qkpow(a,mod-2,mod);
 }//简单欧拉定理
 ```
  2. 实质即ax+by%p=1的不定方程求解（取b=p即可）
  
  解不定方程用的方法叫exgcd(扩展欧几里德算法)
 ```cpp
 void Exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) x = 1, y = 0;
    else Exgcd(b, a % b, y, x), y -= a / b * x;
} 
 i mol p的逆：先定义好x,y,调用exgcd(i,p,x,y),输出x%p就可
 ```

  3. 线性算法：在算一连串的逆比上两个快：
 设p=k*i+r;
  
  k*i+r==0(mod p)
  
  multi i^-1,r^-1
  
  k*r^-1+i^-1==0;
  
  i^-1 == -k*r^-1;
  
  i^-1 == -[p/i]*(p mol i )^-1
  
  由此知当然是可从i=1一直往后递推得到一连串的
  
  代码：
  ```cpp
  inv[1] = 1;
 for(int i = 2; i < p; ++ i)
    inv[i] = (p - p / i) * inv[p % i] % p;
```

# 可持续化线段树
 过程详解：见知乎收藏文章
 
 代码（luoguP3919):
 ```cpp
 #include <bits/stdc++.h>
using namespace std;
int read()
{
    int ans = 0, sgn = 1;
    char c = getchar();
    while (!isdigit(c))
    {
        if (c == '-')
            sgn *= -1;
        c = getchar();
    }
    while (isdigit(c))
    {
        ans = ans * 10 + c - '0';
        c = getchar();
    }
    return ans * sgn;
}
const int MAXV = 20000000, MAXN = 1000005;
#define ls(x) tree[x].ls
#define rs(x) tree[x].rs
#define val(x) tree[x].val
#define mark(x) tree[x].mark
struct node
{
    int val, ls, rs;
} tree[5*MAXV];//动态开点会好一点
int A[MAXN], roots[MAXN], n, m, cnt = 1; // roots记录每个历史版本的根节点
void build(int l = 1, int r = n, int p = 1)
{
    if (l == r)
        val(p) = A[l];
    else
    {
        ls(p) = ++cnt, rs(p) = ++cnt;
        int mid = (l + r) / 2;
        build(l, mid, ls(p));
        build(mid + 1, r, rs(p));
        val(p) = val(ls(p)) + val(rs(p));
    }
}
//!update更新新的节点同时保留过去版本：也即新建一个节点来储存新的内容。其余完全同线段树
void update(int x, int d, int p, int q, int cl = 1, int cr = n) // 单点修改 
{
    if (cl == cr)
        val(q) = d;
    else
    {
        ls(q) = ls(p), rs(q) = rs(p);
        int mid = (cl + cr) / 2;
        if (x <= mid)
            ls(q) = ++cnt, update(x, d, ls(p), ls(q), cl, mid);
        else
            rs(q) = ++cnt, update(x, d, rs(p), rs(q), mid + 1, cr);
        val(q) = val(ls(q)) + val(rs(q));
    }
}
int query(int l, int r, int p, int cl = 1, int cr = n) // 区间查询
{
    if (cl > r || cr < l)
        return 0;
    else if (cl >= l && cr <= r)
        return val(p);
    else
    {
        int mid = (cl + cr) / 2;
        return query(l, r, ls(p), cl, mid) + query(l, r, rs(p), mid + 1, cr);
    }
}
int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; ++i)
        A[i] = read();
    build();
    roots[0] = 1;
    for (int t = 1; t <= m; ++t)
    {
        int v = read(), o = read();
        if (o == 1)
        {
            int x = read(), d = read();
            roots[t] = ++cnt; // 新建节点
            update(x, d, roots[v], roots[t]);
        }
        else
        {
            int x = read();
            roots[t] = roots[v]; // 复用v号版本
            printf("%d\n", query(x, x, roots[v]));
        }
    }
    return 0;
}
```

## 对于可持续化线段树的区间修改

 若是普通线段树，会用lazy tag去修改sum数组的值，利用spread操作

 !这里可持续化线段树中只用lazy tag记录当前区间应该怎么改

 !!关键是lazy tag不下传

 搜索时向下传lazy tag
```cpp 
 void pushup(int id,int l,int r)
{
    //当前区间的值等于左右子节点的值的和加上当前区间的lazy标记	                
    sum[id]=sum[ln[id]]+sum[rn[id]]+(r-l+1)*lazy[id];
}
```
 ## 区间更新
l和r为当前区间左右端点，L和R为目标区间左右端点
```cpp 
 void update_interval(int pre,int id,int L,int R,int val,int l,int r)
 {
 	ln[id]=ln[pre];rn[id]=rn[pre],sum[id]=sum[pre],lazy[id]=lazy[pre];
 	if(l>=L&&r<=R)
 	{
 		lazy[id]+=val;
 		sum[id]+=(r-l+1)*val;
 		return ;
 	}
 	int mid=l+r>>1;
 	if(L<=mid) ln[id]=++idx,update_interval(ln[pre],ln[id],L,R,val,l,mid);
 	if(mid+1<=R) rn[id]=++idx,update_interval(rn[pre],rn[id],L,R,val,mid+1,r);
 	pushup(id,l,r);
 }
```
 ## 区间查询
  l和r为当前区间左右端点，L和R为目标区间左右端点
  
  询问时需要下传lazy，因为没有spread操作，参数中要有lz
 ```cpp
 ll query_interval(int id,int L,int R,ll lz,int l,int r)
 {
 	if(l>=L&&r<=R) return lz*(r-l+1)+sum[id];
 	int mid=l+r>>1;
 	ll ans=0;
 	if(L<=mid) ans+=query_interval(ln[id],L,R,lz+lazy[id],l,mid);
 	if(mid+1<=R) ans+=query_interval(rn[id],L,R,lz+lazy[id],mid+1,r);
 	return ans;
 }
```

- 应用一：利用可持久化线段树求静态区间第k小数的方法
 luoguP3834


# 离散化:只关心偏序关系不关心实际大小

- 一.按大小偏序关系不变：即先创立副本，排序，去重，查找每个元素在副本中的位置，排名作为离散化后的值
```cpp
 for (int i = 1; i <= n; ++i)  // step 1
  tmp[i] = arr[i];
 std::sort(tmp + 1, tmp + n + 1);                          // step 2
 int len = std::unique(tmp + 1, tmp + n + 1) - (tmp + 1);  // step 3
 for (int i = 1; i <= n; ++i)                              // step 4
  arr[i] = std::lower_bound(tmp + 1, tmp + len + 1, arr[i]) - tmp;
 //(查找即二分，lower_bound)
 ```
 复杂度：nlnn

- 二.根据输入顺序离散化为不同数据对数据建立结构体标明出现顺序与值将副本从小到大排序，相同值按顺序从小到大排序
  
  离散化后数组放回原数组
 ```cpp
 struct Data {
  int idx, val;

  bool operator<(const Data& o) const {
    if (val == o.val)
      return idx < o.idx;  // 当值相同时，先出现的元素离散化后的值更小
    return val < o.val;
  }
 }  tmp[maxn];  // 也可以使用 std::pair

 for (int i = 1; i <= n; ++i) tmp[i] = (Data){i, arr[i]};
 std::sort(tmp + 1, tmp + n + 1);
 for (int i = 1; i <= n; ++i) arr[tmp[i].idx] = i;

```

# 莫队算法
 莫队是处理区间问题的乱搞神器，
 
 尤其是对于离线查询问题，因为会对查询做一些预处理
 
 当然也可以做在线查询，比如带修莫队。
 
 对查询先进行预处理，即排序
 
 因为如果是在一个区间已经处理了的情况下，另一个区间只需这个区间首尾平移很近的距离
 
 那么这个计算量就完全可以接受
 
 挪动操作：
 ```cpp
  //ans1是上一次查询的左端点，ans2是上一次查询的右端点
  //lef是当前查询的左端点，rig是当前查询的右端点
 while(ans1>lef) ans1--,add(a[ans1]);//add是扩展函数
 while(ans2<rig) ans2++,add(a[ans2]);
 while(ans1<lef) del(a[ans1]),ans1++;//del是删除函数
 while(ans2>rig) del(a[ans2]),ans2--;
 ```
 其中add和del表示挪动端点x过程中要改变什么,
 
 排序操作：先分块成sqrt(n)块，然后先将这些区域按左端点l所在的块从左到右排序
 
 再把l所在相同区间按r从小到大排序
 
 （说人话就是从内含（不一定完全包含，所以顺序可以规定先左后右）的小区间往外扩）
```cpp
 int block=sqrt(n);
 inline bool cmp(node x,node y){
	 if((x.l-1)/block==(y.l-1)/block) return x.r<y.r;
	 return x.l/block<y.l/block;
 }

```

# vector
 vector:实际啊可以理解为一个长度可变的数组、支持随机访问，删改一般在末尾

 头文件：include <vector>

```vector <int> a //相当于一个长度动态变化的数组```

 ```vector <int> b[233]  //相当与第一维长233，第二维长度变化的int数组```

 迭代器：相当于stl容器的指针


# set & multiset
 分别代表有序集合与有序多重集
 
 内部实现：实质是红黑树，与优先队列一样，储存元素要先定义小于号
 
 insert()插入操作：时间复杂度为log n


# map
 建立一个key-value的映射，实质是一个以key为关键码的红黑树
 
 key必须定义小于号：``` map<key_type , value_type> name;```
 
 example 
 ```map <string ,int>hash``` :实质是一个哈希表
 
 操作：log(n)
 
 h[key]:就是value,若找不到key,则会新建一个(key,0),即h[key]=0,所以找之前
 最好先find

 这个特性反而可以用来建立表统计字符串出现个数
 ```cpp
 map <string,int> h;
 char str[25];
 for(int i=1;i<=n;i++){
    scanf("%s",str);h[str]++;
 }
  //下为m次询问：
  for(int i=1;i<=m;i++)
  {
    scanf("%s",str);
    if(h.find(str)==h.end())puts("0");
    else 
  }
```

# bitset:
 多位二进值数，相当于状态压缩的而二进制数组
 
 位运算ok,s[k]表示第几位，s[0]最低为，
 
 s.count()返回多少个一
 
 s.set(),所有为变成1,reset()变成0
 
 s.set(k,v)把s的第k位改成v,即s[k]=v;


<font>