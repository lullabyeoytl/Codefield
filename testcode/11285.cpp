#include<bits/stdc++.h>
using namespace std;
struct edge{
    bool vi[1501];
    int du;
}edg[1501];
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
bool cmp(struct edge a,struct edge b)
{
    return a.du>b.du;
}
int main()
{
    int n=read();
    for(int i=1;i<=n;i++)
    {
        int t=read(),ti=read();
        edg[t].du+=ti;
        for(int j=1;j<=ti;j++)
        {
            int ki=read();
            edg[t].vi[ki]=1;
            edg[ki].vi[t]=1;
            edg[ki].du+=1;
        }
    }
    int cnt =0;int res=0;
    while(cnt!=n-1)
    {
        int maxn=-1;int targ=0;
       for(int i=0;i<n;i++)
       {
           if(edg[i].du>maxn)
           {
            maxn=edg[i].du;
             targ=i;
           }
       }
        res++;
        cnt+=edg[targ].du;
        for(int j=0;j<n;j++)
        {
            if(edg[targ].vi[j])
            {
                edg[j].du-=1;
                edg[j].vi[targ]=0;
            }
        }
        edg[targ].du=0;
        memset(edg[targ].vi,0,sizeof(edg[targ].vi));
    }
    printf("%d",res);
    system("pause");
    return 0;
} 