#include <bits/stdc++.h>
using namespace std;
int a[200001],b[200005];
int vis[200001];
typedef pair<int ,int> P;
priority_queue<P,vector<P>,greater<P> >q;//这是一个小根堆q
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
int main(){
    int n=read(),m=read();
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
        if(a[i]<0)b[i]=-((a[i]-1)/i )+ 1;
        if(b[i]<=m) q.push(make_pair(b[i],i));
    }
    memset(vis,-1,sizeof(vis));
    while(q.size())
    {
        P to=q.top();
        q.pop();
        if(vis[to.first]==-1)
        {
            
        }
    }
   
}