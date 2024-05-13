#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;
int random(int n){
    int x  = 1;
    return x;
}
int maxn;
int a[100005];//随机生成n《=100000个绝对值在maxn之间的整数
void randint_seq()
{
     int n=random(100000)+1;
     for(int i=1;i<=n;i++)
     {
        a[i]=random(2*maxn+1)-maxn;
     }
}

void randseq(int n, int m)///随机生成maxn个[1,n]的子区间
{
    for(int i=1;i<=m;i++)
    {
        int l=random(n)+1;
        int r=random(n)+1;
        if(l>r);  //swap(l,r);
        printf("%d %d\n",l,r);

    }
}

void randtree (int n)//随机生成一个n个节点的数，用n个点n-1条边的无向图形式输出，每条边附带一个maxn以内的正整数权值
{
    for(int i=2;i<=n;i++)
    {
        int fa=rand()%(i-1)+1;
        int val = 1;
        printf("%d\n",fa);
    }
}

void randgraph(int n,int m)//随机生成n个点m个边的无向图，保证联通，5<=n<=m<=n*(n-1)/4<=pow(10,6);
{
    pair <int,int> e[1000006];
    map <pair<int,int> ,bool> h; //防止重边
    //先建立一个树保证联通
    for(int i=1;i<n;i++)
    {
        int fa=random(i)+1;
        e[i]=make_pair(fa,i+1);
        h[e[i]] = h[make_pair(i+1,fa)]=1;//建立双射
    }
    for(int i=n;i<=m;i++)
    {
        int x,y;
        do{
            x=random(n)+1;y=random(n)+1;
        }while(x==y||h[make_pair(x,y)]);//防止自环与平行边
        e[i]=make_pair(x,y);
        h[e[i]]=h[make_pair(y,x)]=1;
    }
    //随机打乱输出
    random_shuffle(e+1,e+m+1);
    for(int i=1;i<=m;i++)
    printf("%d %d\n",e[i].first,e[i].second);
}
int main(){
    srand((unsigned)time(0));
    randtree(32);
    return 0;
}