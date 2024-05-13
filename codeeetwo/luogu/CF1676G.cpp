#include <bits/stdc++.h>
using namespace std;
int fa[200005];
int numi[200005];
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
int main()
{
    int t=read();
    for(int gidd=1;gidd<=t;gidd++)
    {
        memset(fa,0,sizeof(fa));
        memset(numi,0,sizeof(numi));
        fa[1]=1;
        int n=read();
        for(int i=2;i<=n;i++)
        {
            fa[i]=read();
        }
        string col;
        getline(cin,col);
        for(int i=0;i<col.size();i++)
        {
            if(col[i]=='B')numi[i+1]=1;
            if(col[i]=='W')numi[i+1]=-1;
        }
        for(int i=n;i>=1;i--)
        {
            numi[fa[i]]+=numi[i];
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(numi[i]==0)cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}