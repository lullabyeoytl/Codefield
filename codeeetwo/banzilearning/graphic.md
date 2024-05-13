# 图的储存
## 邻接表
 数据被分为多个链表，每个链表代表一个类，每个类有一个代表元素对应表头head，表头构成表头数组 <br>建立邻接表：head与next数组保存的是ver（顶点）数组的下标，相当于指针，0表示指向空
 ```cpp
void add(int x,int y,int z)//加入有向边（x,y),权值为z
{

    ver[++tot]=y;edge[tot]=z;
    next[tot]=head[x];head[x]=tot;//在表头x处插入

}

// 访问从x出发的所有条边：

 for(int i=head[x];i;i=next[i])
<br>{
    
    int y = ver[i],z=edge[i];
    //找到了一条有向边(x,y),权值为z

}
```
空间复杂度o(n+m)
 
 无向图用两条有向边插入就好,适用于大量遍历邻近节点的算法

 ## 邻接矩阵
 a[i][j]=0:i==j,w[i][j],(i,j)属于E， INF,(i,j)不属于E
 空间复杂度o(n*n)

 ## 链式前向星
 把边集数组中的每一条边按照起点从小到大排序，如果起点相同就按照终点从小到大<br>
 并且记录下以某个点为起点的所有边在数组中的起始位置和存储长度<br>
```cpp
 const int maxn = 1005;//点数最大值
 int n, m, cnt;//n个点，m条边
 struct Edge
 {
    int to, w, next;//终点，边权，同起点的上一条边的编号
 }edge[maxn];//边集
 int head[maxn];//head[i],表示以i为起点的第一条边在边集数组的位置（编号）
 void init()//初始化
 {
    for (int i = 0; i <= n; i++) head[i] = -1;
    cnt = 0;
 }

 void add_edge(int u, int v, int w)//加边，u起点，v终点，w边权
 {

    edge[cnt].to = v; //终点
    edge[cnt].w = w; //权值
    edge[cnt].next = head[u];//以u为起点上一条边的编号，也就是与这个边起点相同的上一条边的编号
    head[u] = cnt++;//更新以u为起点上一条边的编号
 }
  for (int i = 1; i <= m; i++)//输入m条边
    {

        cin >> u >> v >> w;
        add_edge(u, v, w);//加边
        //加双向边
        //add_edge(u, v, w);
        //add_edge(v, u, w);
        
        
    }

```
# 单源最短路径 ： 
## DIJKSTRA算法
 给定一张有向图G（V,E），n个点m个边，节点【1，n】连续编号，（x，y，z）表示一条从x开始到达y长度为z的有向边<br>
 题目：设一号店为起点，求长度为n的数组dist，其中dist【i】表示从节点1到节点i的最短路径长度<br>
  算法过程:贪心，见代码：<br>
  int a[3030][3030],d[3030],n,m;<br>
  bool v[3030];//标记数组；<br>
  void dijkstra()
  {

    memset(d,0x3f,sizeof(d));//先全部初始化为正无穷
    memset(v,0,sizeof(v));//节点标记初始化
    d[1]=0;//标记起点
    for(int i=1;i<n;i++){
        int x=0;
        //找到未标记节点中dist最小的
        for(int j=1;j<=n;j++)
        if(!v[j]&&(x==0||d[j]<d[x]))x=j;
        v[x]=1;//找到未标记节点中dist最小的并标记,有贪心知这个最小肯定更新不了了，那就是最优的
        //下用全局最小值点x更新其他节点
        for(int y=1;y<=n;y++)
        {
            d[y]=min(d[y],d[x]+a[x][y]);
        }
    }
}
 <br>// 适用于边权为正，为负贪心错误

 但以上找最小明显可以用优先队列维护：<br>
 priority_queue <pair <int ,int> > q;<br>
 void dijkstra(){

    memset(d,0x3f,sizeof(d));//先全部初始化为正无穷
    memset(v,0,sizeof(v));//节点标记初始化
    d[1]=0;//标记起点
    q.push(make_pair(0,1));//第二维为编号
    while(q.size())
    {
    int x=q.top().second；q.pop();
    if(v[x])continue;
    v[x]=1;//标记过的就没用了，直接pop
    for(int i=1;i<=n;i++)//用邻接表就是(for(int i=head[x];i,i=next[i])
    {
        if(d[i]>d[x]+z)d[y]=d[x]+z;
        q.push(make_pair(-d[y],y));//更新，把新的d[y]扔进去
    }
    //这里其实可以看到邻接矩阵的劣势：其实根本不用枚举n个只要枚举相连边就ok
    //用邻接表效率更好
   }
}
## Bellaman-Ford算法：（SPFA）
 最短路显然满足：d[y]<d[x]+z,任意(x,y)；<br>
 操作是：1建立一个队列，起初只有起点1<br>
        2.取出节点x,扫描它的所有出边（x,y,z),若dist[y]》dist[x]+z,则使用dist[x]+z更新dist[y]，若y不在队列中则把y入队<br>
       3.重复操作直到队列为空<br>
 注意到此处只是在迭代并未贪心取得最优（在非负前提贪心），这个迭代完全可以使用与边权为负数的情况<br>
 若用优先队列做一个局部优化：dj算法<br>
 代码把priority_queue换成queue就好
 */

 /* 
 
 # 若是离线询问一条从1到N的路径中第k+1短路最小值：
 
 ## 法一：
 可以二分答案：mid，把大于mid的看作边长为一的边，小于mid的看作长度为0的边，然后求1-n最短路是否超过k<br>
 这个可以用双端队列深搜加广搜：若为1从队尾进入（广搜）更新边长，若为0则从队头进入（深搜模板），改进用A*算法，h值设为已知点之间最短值<br>
 （像并查集，树状数组的那个排序后在生成的思想）<br>
 ## !法二：分层图最短路：
 可以考虑二元组（x,p)表示节点，x,p到（y，p）有长度为z的边，（x，p）到（y，p+1）有长为0的边<br>
 那么假设k层n个点，把一个图的情况拷贝n次，一个点编号t,t+n,……t+(k-1)*n这种方式建图<br>
 然后dj算法

*/ 
# 任意两点的最短路径：
 ## floyd算法：
 设d（k，i，j）表示“经过若干编号不超过k的节点”从i到j的最短路长度<br>
 dp：d（k，i，j）=min(d(k-1,i,j),d(k-1,i,k)+d(k-1,k,j))<br>
 显然这里k才是“阶段”，i，j是内层枚举：<br>
 dp如下：<br>
 int d[310][310],N,M;<br>
 int main()
 {

    cin>>n>>m;
    memset(d,0x3f,sizeof(d));
    for(int i =1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        d[x][y]=min(d[x][y],z);
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    //output
 }
*/
# 全源最短路之Johnson题解
任意两点间的最短路可以通过枚举起点，跑n 次 Bellman-Ford 算法解决，时间复杂度是n^2*m

也可以直接floyd,复杂度为n^3

若边权是都正的那用dj算法会很快，nmlogm量级

所以遇到有负边权的要进行预处理，但显然不能简单江边权平移某个大小，因为不能保证加入的边权权值占比会一样

Johnson算法入下：
1.新建一个节点，设为0，从这个点引其他所有边边权为0的点

2.用BELLMAN-Ford算法求出0号点到其他点单元最短路，即为hi

3.若存在从u到v的点，该边权重新设置为w+hu-hv

接下来以每个节点为起点，跑n轮dj算法，时间复杂度为nmlogm
```cpp
#include <cstring>
#include <iostream>
#include <queue>
#define INF 1e9
using namespace std;
struct edge {
  int v, w, next;
} e[10005];
struct node {
  int dis, id;
  bool operator<(const node& a) const { return dis > a.dis; }
  node(int d, int x) { dis = d, id = x; }
};
int head[5005], vis[5005], t[5005];
int cnt, n, m;
long long h[5005], dis[5005];
void addedge(int u, int v, int w) {
  e[++cnt].v = v;
  e[cnt].w = w;
  e[cnt].next = head[u];
  head[u] = cnt;
}
bool spfa(int s) {
  queue<int> q;
  memset(h, 63, sizeof(h));
  h[s] = 0, vis[s] = 1;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (int i = head[u]; i; i = e[i].next) {
      int v = e[i].v;
      if (h[v] > h[u] + e[i].w) {
        h[v] = h[u] + e[i].w;
        if (!vis[v]) {
          vis[v] = 1;
          q.push(v);
          t[v]++;
          if (t[v] == n + 1) return false;
        }
      }
    }
  }
  return true;
}
void dijkstra(int s) {
  priority_queue<node> q;
  for (int i = 1; i <= n; i++) dis[i] = INF;
  memset(vis, 0, sizeof(vis));
  dis[s] = 0;
  q.push(node(0, s));
  while (!q.empty()) {
    int u = q.top().id;
    q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (int i = head[u]; i; i = e[i].next) {
      int v = e[i].v;
      if (dis[v] > dis[u] + e[i].w) {
        dis[v] = dis[u] + e[i].w;
        if (!vis[v]) q.push(node(dis[v], v));
      }
    }
  }
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    addedge(u, v, w);
  }
  for (int i = 1; i <= n; i++) addedge(0, i, 0);
  if (!spfa(0)) {
    cout << -1 << endl;
    return 0;
  }
  for (int u = 1; u <= n; u++)
    for (int i = head[u]; i; i = e[i].next) e[i].w += h[u] - h[e[i].v];
  for (int i = 1; i <= n; i++) {
    dijkstra(i);
    long long ans = 0;
    for (int j = 1; j <= n; j++) {
      if (dis[j] == INF)
        ans += j * INF;
      else
        ans += j * (dis[j] + h[j] - h[i]);
    }
    cout << ans << endl;
  }
  return 0;
}
```
# 最小生成树
 定理：最小生成树一定含无向图权值最小的边<br>
 推论：给定一张无向图G=(v,e),从e中选出k<n-1条边构成G的一个生成森林，若再从剩余m-k条边中选出n-1-k条边添加到森林里面
 使g变成生成树。切边权和最小，则该生成树必含这m-k条边中连接生成森林的两个不连通节点权值最小的边

 ## Kruskal算法：流程：
 1.建立并查集，每个点各自构成一个集合<br>
 2.把所有边按权值从小到大排序，依次扫描每条边（x，y，z）<br>
 3，若x，y属于同一集合（连通），则忽略这条边，继续扫描下一条<br>
 4.否则合并x，y，把z累加到答案里（过程可以理解为推论的反复使用）<br>
 时间复杂度o(mlogm)<br>
```cpp
 struct edge 
{
    int x,y,z;
}edge[500010];
 int fa[100010],n,m,ans;
 bool operrator < (rec a, rec b)
 {
    return a.z<b.z;
 }
 int get(int x)
{

    if(x==fa[x])
    return x;
    return fa[x]=get(fa[x]);
}
 int main()
{

    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&edge[i].x,&edge[i].y,&edge[i],z);
    }//按边权排序
    sort(edge+1,edge+m+1);
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        int x=get(edge[i].x);
        int y=get(edge[i].y);
        if(x==y)continue;
        fa[x]=y;//都不需要压缩路径直接连
        ans+=edge[i].z;
    }
    cout>>ans<<endl;
}
```
  ## Prim算法：
（相当于上面的一个小优化）<br>任意时刻以确定的最小生成树集合为T，剩余集合为S。Prim算法找到min(x属于S，y属于T){z}
 然后把x放到t中，z加到答案里<br>
 可以用数组标记是否属于t<br>
 适用范围：稠密图，用优先队列可优化到mlogn<br>
 const int maxn=2e5+15;<br>
 const int mxn=5e3+15;<br>
 struct node
{

    int t;int d;
    bool operator < (const node &a) const
    {
        return d>a.d;
    }
};<br>
 int n,m;<br>
 int vis[mxn];
 vector <node> e[mxn];<br>
 priority_queue <node> q;<br>
 inline int read()
{

    char ch=getchar();
    int s=0,f=1;
    while (!(ch>='0'&&ch<='9')) {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') {s=(s<<3)+(s<<1)+ch-'0';ch=getchar();}
    return s*f;
}
 ll prim()
{

    ll ans=0;
    int cnt=0;
    q.push((node){1,0});
    while (!q.empty()&&cnt<=n)
    {
        node k=q.top();q.pop();
        if (vis[k.t]) continue;
        vis[k.t]=1;
        ans+=k.d;
        cnt++;
        for (int i=0;i<e[k.t].size();i++)
        if (!vis[e[k.t][i].t]){
            q.push((node){e[k.t][i].t,e[k.t][i].d});
        }
    }
    return ans;
}
 int main()
{

    n=read();m=read();
    for (int i=1;i<=m;i++)
    {
        int x=read(),y=read(),z=read();
        e[x].push_back((node){y,z});e[y].push_back((node){x,z});
    }
    printf("%lld",prim());
    return 0;
}

 }

*/

# 找连通块：
 用stack写个深搜就好<br>
 int k=0,cnt=0;<br>
 stack <int> sta;<br>
 int v[maxn]; <br>
 void add(int x,int y,int z)//加入有向边（x,y),权值为z
{

    ver[++tot]=y;edge[tot]=z;
    next[tot]=head[x];head[x]=tot;//在表头x处插入
}
 sta.push(1);k=1;cnt=1;v[1]=1;//cnt编号连通块；<br>
 while(k<n)
 {

    while(sta.size())
    {
        int t=sta.top();
        sta.pop();
        for(int i=head[t];i;i=next[i])
        {
            if(!v[i])
            {
                v[i]=cnt;k++;
                sta.push(i);
            }
        }
    }
    cnt++;
 }
*/

# 树的直径
 直径：最远两节点距离<br>
 法一：树形dp：d[x]:从节点x出发能到达节点最远距离<br>
 d[x]=max(1<=i<=t){d[yi]+edge(x,yi)}<br>
 f[x]:经过x的最长连长度：<br>
 f[x]=max(1<j<i<=t){d[yi]+d[yj]+edge(x,yi)+edge(x,yj)}<br>
 注意到计算d[x]枚举到i是已经是max d[yi]+edge(x,yi)<br>
 所以先用d[x]+d[yi]+edge(x,yi)更行f[x],在用d[yi]+edge(x,yi)更新d[x]就好：<br>
 void dp(int x)
{
    
    v[x]=1;
    for(int i=head[x];i;i=next[i])
    {
    int y=ver[i];
    if(v[y])continue;
    dp(y);//树形dp一般采用递归
    ans=max(ans,d[x]+d[y]+edge[i]);
    d[x]=max(d[x],d[y]+edge[i]);
    //上述两个更新
    }
}

 法二：两次搜索：从任意一个节点出发，遍历树，记录最远节点p<br>
 2.从p出发，遍历树，求出距离p最远的节点q<br>
 p,q为直径<br>
 适用范围，边均为正
*/

# 最小公共祖先问题（LCA）
 ## 树上倍增法：
 记f[x,k]为x的2^k次方祖先，若不存在即为0<br>
 f[x,0]即为x的父节点<br>
 f[x,k]=f(f[x,k-1],k-1); 预处理f数组<br>
 下为算法步骤：<br>
 d[x]标为x的深度<br>
 首先先两者调为同一高度<br>
 然后x，y同时向上调整k=pow(2,log n) …… 2，1步（幂次从大到小试）<br>
 若未向会，则x=f(x,k),y=f(y,k)<br>
 复杂度：o((n+m)log n)<br>

 const int size = 50010;<br>
 int f[size][20],d[size],dist[size];<br>
 int ver [2*size],next[2*size],edge[size*2],head[size];<br>
 int T,n,m,tot,t;<br>
 queue <int> q;<br>

 void add(int x,int y,int z)
 {

    ver[++tot]=y;edge[tot]=z;next[tot]=head[x];head[x]=tot;
 }//邻接表

 void bfs(){

    //预处理
    q.push(1);d[1]=1;
    while(q.size()){
        int x =q.front();q.pop();
        for(int i=head[x];i;i=next[i]){
            int y = ver[i];
            if(d[y])continue;
            d[y]=d[x]+1;
            dist[y]=dist[x]+edge[i];
            f[y][0]=x;
            for(int j=1;j<=t;j++)
           f[y][j]=f[f[y][j-1]][j-1];
           q.push(y);
        }
    }
 }

 int lca(int x,int y)//回答一个询问
 {

    if(d[x]>d[y])swap(x,y);
    for(int i=t;i>=0;i--)
    if(d[f[y][i]]>=d[x])y=f[y][i];//先调到同一高度
    if(x==y)return x;
    for(int i=t;i>=0;i--)
    if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
    return f[x][0];
 }

 int main()
 {

    cin>>T;
    while(T--){
        cin>>n>>m;
        t=(int)(log(n)/log(2))+1;
        memset(head,0,sizeof(head));
        memset(d,0,sizeof(d));
        tot=0;
        //读树
        for(int i=1;i<=n;i++)
        {
            int x.y,z;
            scanf("%d%d",&x,&y);
            add(x,y,z);add(y,x,z);
        }
        bfs();
        for(int i=1;i<=m;i++)
        {
            int x, y;
            scanf("%d%d",&x,&y);
            printf("%d\n",dist[x]+dist[y]-2*dsit[lca(x,y)]);
        }
    }
 }
*/
# lca的Tarjan算法:
  离线算法，时间复杂度o(n+m)，节点分为三类：


  * 已经访问完毕并且回溯的节点，标记为二
  * 已经开始递归，但尚未回溯的节点。这些节点就是当前正在访问的节点x及其祖先，标记为1
  * 尚未访问的节点，这些节点没有标记。
   
若x正在访问，y已经访问完了，则lca（x，y）就是从y向上走到根，第一个遇到的节点(拓扑序)
<br>可以利用并查集优化，当一个节点标记为2的时候，把他所在集合合并到父节点里）（自底向上，合并时显然父节点标记为1）

code：
```cpp
const int SIZE = 50010;
int ver[2*SIZE],next[2*SIZE],edge[2*SZIE],head[SIZE];
int fa[SIZE], d[SIZE], v[SZIE],lca[SZIE],ans[SIZE];
vector <int> query[SIZE],query_id[SIZE];
int T,n,m,tot,t;

void add(int x,int y,int z){
    ver[++tot]=y;edge[tot]=z;next[tot]=head[x];head[x]=tot;
}

void add_query (int x,int y ,int id){
    query[x].push_back(y),query_id[x].push_back(id);
    query[y].push_back(x),query_id[y].push_back(id);
}

int get(int x)
{
    if(x==fa[x]) return x;
    else
    return fa[x]=get(fa[x]);
}

//由上tarjan就是拓扑序加一个并查集优化
void tarjan(int x){
    v[x]=1；
    for(int i =head[x];i;i=next[x]){
        int y=ver[i];
        if(v[y]) continue;
        d[y] = d[x] +edge[i];
        tarjan(y);
        //递归为y的向上回溯
        fa[y]=x;
    }
    //x的子节点全部回溯完
    for(int i=0;i< query[x].size();i++)
    {
        int y=query[x][i],id=query[x][i];
        if (v[y]==2){
            int lca = get(y);//lca
            ans[id] = min(ans[id],d[x]+d[y]-2*d[lca]);//利用求的lca（x，y）求得x到y的距离
        }
    }
    v[x]=2;
}

int main(){
    cin>>T;
    while(T--){
        cin >>n>>m;
        for(int i=1;i<=n;i++){
            head[i]=0;fa[i]=i;v[i]=0;
            query[i].clear(),query_id[i].clear();
        }
    tot = 0;
    for(int i=1;i<n;i++)
    {
        int x,y,z;
        sacnf("%d%d%d",&x,&y,&z);
        add(x,y,z),add(y,x,z);
    }
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x==y) ans[i] = 0;
        else{
            add_query(x,y,i);
            ans[i]=1<<30;
        }
    }
    tarjan(1);
    for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
  }
}
```

 
# 二叉树前序，中序，后序遍历
https://blog.csdn.net/qq_61959780/article/details/127690872<br>
前序遍历：code<br>
/*先序遍历*/<br>
void PreOrder(BiTree T)
{

	if (T != NULL)
	{ 
		visit(T);              // 访问结点              
		PreOrder(T->lchild);   // 遍历结点左子树
		PreOrder(T->rchild);   // 遍历结点右子树
	}
}
 
/*输出树结点*/<br>
void visit(BiTree T)
{

	printf("树结点的值：%c\n", T->data);
}
就是从左到右，到一个节点就输出一直左到底，<br>
不行或结束了返回到右<br>
先输出，再左树先序遍历，再右树先序遍历

/*中序遍历*/<br>
void InOrder(BiTree T)
{

	if (T != NULL)
	{
		InOrder(T->lchild);    // 遍历结点左子树
		visit(T);              // 访问结点
		InOrder(T->rchild);    // 遍历结点右子树
	}
}
 
/*输出树结点*/
```
void visit(BiTree T)
{
    printf("树结点的值：%c\n", T->data);
}
```
先一直到左，不行了在输出此点，再到右一位，开始重复（详见递归）
先中序遍历，再输出，再有序遍历

/*后序遍历*/<br>
void PostOrder(BiTree T)
{

	if (T != NULL)
	{
		PostOrder(T->lchild);	// 遍历结点左子树
		PostOrder(T->rchild);	// 遍历结点右子树
		visit(T);				// 访问结点
	}
}
 
/*输出树结点*/<br>
void visit(BiTree T)
{

	printf("树结点的值：%c\n", T->data);
}
*/

# 树的重心
定义：计算以无根树每个点为根节点时的最大子树大小，这个值最小的点称为无根树的重心。
## 性质1：某点是树的重心等价于它最大子树不大于整棵树大小的一半
那么根据这个结合深搜就可以找到重心<br>
void dfs(int x){

    v[x]=1;size[x]=1;//v记录是否访问过，size记录删除x后分成的最大子树的大小
    int max_part = 0;
    for(int i=head[x];i;i=next[i]){
        int y = ver[i];
        if(v[y])continue;
        dfs(y);
        size[x] += size[y];//从子节点向父节点递推
        max_part = max(max_part,size[y]);
    }
    max_part = max(max_part,n-size[x]);
    if(max_part<ans){
        ans=max_part;//全局变量ans记录重心对应的max_part值
        pos=x;//全局变量pos记录了重心
    }
}
## 性质2：树最多两个重心，若有两个则它们相邻
## 性质3：树中所有点到某个点的距离和中，到重心的距离和是最小的；如果有两个重心，那么到它们的距离和一样。反过来，距离和最小的点一定是重心。
## 性质4：往树上增加或减少一个叶子，如果原节点数是奇数，那么重心可能增加一个，原重心仍是重心；如果原节点数是偶数，重心可能减少一个，另一个重心仍是重心。

<br>

# 【模板】重链剖分/树链剖分

### 题目描述

如题，已知一棵包含 $N$ 个结点的树（连通且无环），每个节点上包含一个数值，需要支持以下操作：

- `1 x y z`，表示将树从 $x$ 到 $y$ 结点最短路径上所有节点的值都加上 $z$。

- `2 x y`，表示求树从 $x$ 到 $y$ 结点最短路径上所有节点的值之和。

- `3 x z`，表示将以 $x$ 为根节点的子树内所有节点值都加上 $z$。

- `4 x` 表示求以 $x$ 为根节点的子树内所有节点值之和

### 输入格式

第一行包含 $4$ 个正整数 $N,M,R,P$，分别表示树的结点个数、操作个数、根节点序号和取模数（**即所有的输出结果均对此取模**）。

接下来一行包含 $N$ 个非负整数，分别依次表示各个节点上初始的数值。

接下来 $N-1$ 行每行包含两个整数 $x,y$，表示点 $x$ 和点 $y$ 之间连有一条边（保证无环且连通）。

接下来 $M$ 行每行包含若干个正整数，每行表示一个操作。

### 输出格式

输出包含若干行，分别依次表示每个操作 $2$ 或操作 $4$ 所得的结果（**对 $P$ 取模**）。


## 方法：树链剖分

树链剖分<br>
树链剖分 就是对一棵树分成几条链，把树形变为线性，减少处理难度<br>
概念

重儿子：对于每一个非叶子节点，它的儿子中 以那个儿子为根的子树节点数最大的儿子 为该节点的重儿子 

轻儿子：对于每一个非叶子节点，它的儿子中 非重儿子 的剩下所有儿子即为轻儿子
叶子节点没有重儿子也没有轻儿子（因为它没有儿子。。）

重边：一个父亲连接他的重儿子的边称为重边 //原写法：连接任意两个重儿子的边叫做重边

轻边：剩下的即为轻边

重链：相邻重边连起来的 连接一条重儿子 的链叫重链

对于叶子节点，若其为轻儿子，则有一条以自己为起点的长度为1的链

每一条重链以轻儿子为起点

### dfs1()

这个dfs要处理几件事情：

标记每个点的深度dep[]

标记每个点的父亲fa[]

标记每个非叶子节点的子树大小(含它自己)

标记每个非叶子节点的重儿子编号son[]
```cpp
inline void dfs1(int x,int f,int deep){//x当前节点，f父亲，deep深度 
	dep[x]=deep;//标记每个点的深度 
	fa[x]=f;//标记每个点的父亲 
	siz[x]=1;//标记每个非叶子节点的子树大小 
	int maxson=-1;//记录重儿子的儿子数 
	for(Rint i=beg[x];i;i=nex[i]){
		int y=to[i];
		if(y==f)continue;//若为父亲则continue 
		dfs1(y,x,deep+1);//dfs其儿子 
		siz[x]+=siz[y];//把它的儿子数加到它身上 
		if(siz[y]>maxson)son[x]=y,maxson=siz[y];//标记每个非叶子节点的重儿子编号 
	}
}
```

### dfs2()

这个dfs2也要预处理几件事情

标记每个点的新编号

赋值每个点的初始值到新编号上

处理每个点所在链的顶端

处理每条链

顺序：先处理重儿子再处理轻儿子，理由后面说
```cpp
inline void dfs2(int x,int topf){//x当前节点，topf当前链的最顶端的节点 
	id[x]=++cnt;//标记每个点的新编号 
	wt[cnt]=w[x];//把每个点的初始值赋到新编号上来 
	top[x]=topf;//这个点所在链的顶端 
	if(!son[x])return;//如果没有儿子则返回 
	dfs2(son[x],topf);//按先处理重儿子，再处理轻儿子的顺序递归处理 
	for(Rint i=beg[x];i;i=nex[i]){
		int y=to[i];
		if(y==fa[x]||y==son[x])continue;
		dfs2(y,y);//对于每一个轻儿子都有一条从它自己开始的链 
	}
}
```

## 第三步

因为顺序是先重再轻，所以每一条重链的新编号是连续的

因为是dfs，所以每一个子树的新编号也是连续的（以上两者达成剖分成链的条件）

现在回顾一下我们要处理的问题

处理任意两点间路径上的点权和<br>
处理一点及其子树的点权和<br>
修改任意两点间路径上的点权<br>
修改一点及其子树的点权<br>
1、当我们要处理任意两点间路径时：
设所在链顶端的深度更深的那个点为x点

ans加上x点到x所在链顶端 这一段区间的点权和

把x跳到x所在链顶端的那个点的上面一个点

不停执行这两个步骤，直到两个点处于一条链上，这时再加上此时两个点的区间和即可

这时我们注意到，我们所要处理的所有区间均为连续编号(新编号)，于是想到线段树，用线段树处理连续编号区间和
每次查询时间复杂度为O(logn^2)
```cpp
inline int qRange(int x,int y){
	int ans=0;
	while(top[x]!=top[y]){//当两个点不在同一条链上 
		if(dep[top[x]]<dep[top[y]])swap(x,y);//把x点改为所在链顶端的深度更深的那个点
		res=0;
		query(1,1,n,id[top[x]],id[x]);//ans加上x点到x所在链顶端 这一段区间的点权和
		ans+=res;
		ans%=mod;//按题意取模 
		x=fa[top[x]];//把x跳到x所在链顶端的那个点的上面一个点
	}
	//直到两个点处于一条链上
	if(dep[x]>dep[y])swap(x,y);//把x点深度更深的那个点
	res=0;
	query(1,1,n,id[x],id[y]);//这时再加上此时两个点的区间和即可
	ans+=res;
	return ans%mod;
}//变量解释见最下面
```
2、处理一点及其子树的点权和：

想到记录了每个非叶子节点的子树大小(含它自己)，并且每个子树的新编号都是连续的

于是直接线段树区间查询即可
时间复杂度为O(logn)

```cpp
inline int qSon(int x){
	res=0;
	query(1,1,n,id[x],id[x]+siz[x]-1);//子树区间右端点为id[x]+siz[x]-1 
	return res;
}
//查询
inline void updRange(int x,int y,int k){
	k%=mod;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		update(1,1,n,id[top[x]],id[x],k);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	update(1,1,n,id[x],id[y],k);
}

inline void updSon(int x,int k){
	update(1,1,n,id[x],id[x]+siz[x]-1,k);
}//变量解释见最下面

```

ac代码：
```cpp
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#define Rint register int
#define mem(a,b) memset(a,(b),sizeof(a))
#define Temp template<typename T>
using namespace std;
typedef long long LL;
Temp inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}

#define mid ((l+r)>>1)
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
#define len (r-l+1)

const int maxn=200000+10;
int n,m,r,mod;
//见题意 
int e,beg[maxn],nex[maxn],to[maxn],w[maxn],wt[maxn];
//链式前向星数组，w[]、wt[]初始点权数组 
int a[maxn<<2],laz[maxn<<2];
//线段树数组、lazy操作 
int son[maxn],id[maxn],fa[maxn],cnt,dep[maxn],siz[maxn],top[maxn]; 
//son[]重儿子编号,id[]新编号,fa[]父亲节点,cnt dfs_clock/dfs序,dep[]深度,siz[]子树大小,top[]当前链顶端节点 
int res=0;
//查询答案 

inline void add(int x,int y){//链式前向星加边 
    to[++e]=y;
    nex[e]=beg[x];
    beg[x]=e;
}
//-------------------------------------- 以下为线段树 
inline void pushdown(int rt,int lenn){
	laz[rt<<1]+=laz[rt];
	laz[rt<<1|1]+=laz[rt];
    a[rt<<1]+=laz[rt]*(lenn-(lenn>>1));
    a[rt<<1|1]+=laz[rt]*(lenn>>1);
    a[rt<<1]%=mod;
    a[rt<<1|1]%=mod;
    laz[rt]=0;
}

inline void build(int rt,int l,int r){
    if(l==r){
        a[rt]=wt[l];
        if(a[rt]>mod)a[rt]%=mod;
        return;
    }
    build(lson);
    build(rson);
    a[rt]=(a[rt<<1]+a[rt<<1|1])%mod;
}

inline void query(int rt,int l,int r,int L,int R){
	if(L<=l&&r<=R){res+=a[rt];res%=mod;return;}
	else{
		if(laz[rt])pushdown(rt,len);
		if(L<=mid)query(lson,L,R);
		if(R>mid)query(rson,L,R);
	}
}

inline void update(int rt,int l,int r,int L,int R,int k){
    if(L<=l&&r<=R){
		laz[rt]+=k;
		a[rt]+=k*len;
	}
	else{
		if(laz[rt])pushdown(rt,len);
		if(L<=mid)update(lson,L,R,k);
		if(R>mid)update(rson,L,R,k);
		a[rt]=(a[rt<<1]+a[rt<<1|1])%mod;
	}
}
//---------------------------------以上为线段树 
inline int qRange(int x,int y){
	int ans=0;
	while(top[x]!=top[y]){//当两个点不在同一条链上 
		if(dep[top[x]]<dep[top[y]])swap(x,y);//把x点改为所在链顶端的深度更深的那个点
		res=0;
		query(1,1,n,id[top[x]],id[x]);//ans加上x点到x所在链顶端 这一段区间的点权和
		ans+=res;
		ans%=mod;//按题意取模 
		x=fa[top[x]];//把x跳到x所在链顶端的那个点的上面一个点
	}
	//直到两个点处于一条链上
	if(dep[x]>dep[y])swap(x,y);//把x点深度更深的那个点
	res=0;
	query(1,1,n,id[x],id[y]);//这时再加上此时两个点的区间和即可
	ans+=res;
	return ans%mod;
}

inline void updRange(int x,int y,int k){//同上 
	k%=mod;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		update(1,1,n,id[top[x]],id[x],k);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	update(1,1,n,id[x],id[y],k);
}

inline int qSon(int x){
	res=0;
	query(1,1,n,id[x],id[x]+siz[x]-1);//子树区间右端点为id[x]+siz[x]-1 
	return res;
}

inline void updSon(int x,int k){//同上 
	update(1,1,n,id[x],id[x]+siz[x]-1,k);
}

inline void dfs1(int x,int f,int deep){//x当前节点，f父亲，deep深度 
	dep[x]=deep;//标记每个点的深度 
	fa[x]=f;//标记每个点的父亲 
	siz[x]=1;//标记每个非叶子节点的子树大小 
	int maxson=-1;//记录重儿子的儿子数 
	for(Rint i=beg[x];i;i=nex[i]){
		int y=to[i];
		if(y==f)continue;//若为父亲则continue 
		dfs1(y,x,deep+1);//dfs其儿子 
		siz[x]+=siz[y];//把它的儿子数加到它身上 
		if(siz[y]>maxson)son[x]=y,maxson=siz[y];//标记每个非叶子节点的重儿子编号 
	}
}

inline void dfs2(int x,int topf){//x当前节点，topf当前链的最顶端的节点 
	id[x]=++cnt;//标记每个点的新编号 
	wt[cnt]=w[x];//把每个点的初始值赋到新编号上来 
	top[x]=topf;//这个点所在链的顶端 
	if(!son[x])return;//如果没有儿子则返回 
	dfs2(son[x],topf);//按先处理重儿子，再处理轻儿子的顺序递归处理 
	for(Rint i=beg[x];i;i=nex[i]){
		int y=to[i];
		if(y==fa[x]||y==son[x])continue;
		dfs2(y,y);//对于每一个轻儿子都有一条从它自己开始的链 
	}
}

int main(){
    read(n);read(m);read(r);read(mod);
    for(Rint i=1;i<=n;i++)read(w[i]);
    for(Rint i=1;i<n;i++){
        int a,b;
        read(a);read(b);
        add(a,b);add(b,a);
    }
    dfs1(r,0,1);
    dfs2(r,r);
    build(1,1,n);
	while(m--){
        int k,x,y,z;
        read(k);
        if(k==1){
            read(x);read(y);read(z);
            updRange(x,y,z);
        }
        else if(k==2){
            read(x);read(y);
            printf("%d\n",qRange(x,y));
        }
        else if(k==3){
            read(x);read(y);
            updSon(x,y);
        }
        else{
            read(x);
            printf("%d\n",qSon(x));
    	}
    }
}

```

# 树上差分
 ## 一，修改点权，要求u,v,路径经过的点全部增加x
 
 利用差分这样改，num[u]+=x,num[v]+=x,num[lca(u,v)]-=x,num[fa[lca(u,v)]]-=x;

 查询点权：以每个节点为根的节点权值和！这个深搜就可以办到。

 ## 二，边差分，u,v的路径上的所有边加x

操作：num[u]+=x ,num[v]+=x,num[lca(x,y)]-=2*x;

查询边权：以每个节点为根的节点权值和，这个深搜就可以办到。



