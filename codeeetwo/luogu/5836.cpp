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
int fa[100005],ans[100005];bool col[100005];
int get(int x)
 {
    if(fa[x]==x)return x;
    return fa[x]=get(fa[x]);//向上递归并且让经过的点都与根直接相连
 }
 void merge(int x,int y){
    fa[get(x)] = get(y);
 }
 int main()
 {
    int n,m;
    n=read(),m=read();
    string str;
    getline(cin,str);
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
        if(str[i-1]=='H')col[i]=1;
    }
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(col[x]==col[y])
        merge(y,x);
    }
    for(int i=1;i<=m;i++)
    {
        int x,y;char ch;
        scanf("%d %d %c",&x,&y,&ch);
        if(get(x)!= get(y))ans[i]=1;
        else
        {
            if((col[get(x)]==0&&ch=='G')||col[get(x)]==1&&ch=='H')ans[i]=1;
        }
    }
    for(int i=1;i<=m;i++)printf("%d",ans[i]);
    return 0;
 }