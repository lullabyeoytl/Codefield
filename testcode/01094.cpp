#include <bits/stdc++.h>
using namespace std;
int n,stad;int a[200005];
int vis[200005];
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
void adj(int x)
{ 
    if(x==0||a[x]==stad) return;
    if(a[x]!=stad)
    {
        (a[x]>stad)?printf("2 %d %d\n",x,x+1):printf("1 %d %d\n",x,x+1);
        adj(x-1);
    }
}
int main()
{
    n=read();int imax=0,nummax=0,icheck;
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
        vis[a[i]]++;
        if(vis[a[i]]>=imax)
        {
            imax=vis[a[i]];
            nummax=a[i];
            icheck=i;
        }
    }
    stad=nummax;
    printf("%d\n",n-imax);
    for(int i=1;i<=n;i++)
    {
        if(a[i]==stad)adj(i-1);
    }
    for(int i=icheck+1;i<=n;i++)
    {
        a[i]>stad?printf("2 %d %d\n",i,i-1):printf("1 %d %d\n",i,i-1);
    }
    return 0;
}