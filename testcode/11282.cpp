#include<bits/stdc++.h>
using namespace std;
int tot=0;
struct ver
{
    int l,r,num,fa;
}edge[101];
int dfs(int i,int j)//起点 i
{
    int minn=100000000;
    if(dfs(edge[i].fa,j)!=0) 
    minn = min(minn,dfs(edge[i].fa,j)+edge[edge[i].fa].num);
    if(dfs(edge[i].l,j)!=0) 
    minn = min(minn,dfs(edge[i].l,j)+edge[edge[i].l].num);
    if(dfs(edge[i].r,j)!=0) 
    minn = min(minn,dfs(edge[i].r,j)+edge[edge[i].r].num);
    if(minn!=100000000)return 0;
    else return minn;

}
int main()
{
  
    system("pause");
    return 0;
} 