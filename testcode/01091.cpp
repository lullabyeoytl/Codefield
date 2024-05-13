#include <bits/stdc++.h>
using namespace std;
int n;
int vis[30];
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
    n=read();int icheck;
    for(int i=1;i<=n;i++)
    {
        icheck=0;
        memset(vis,0,sizeof(vis));
        char a[105];
        gets(a);
        int amax=0,amin=128;
        for(int j=0;j<strlen(a);j++)
        {
            if(a[j]>amax)amax=a[j];
            if(a[j]<amin)amin=a[j];
            if(vis[a[j]-96]==1)
            {
                printf("No\n");
                icheck=1;
                break;
            }
            vis[a[j]-96]=1;
        }
        if(icheck==1)continue;
        for(int k=amin-96;k<=amax-96;k++)
        {
            if(vis[k]!=1)
            {
                printf("No\n");
                icheck=1;
                break;
            }
        }
        if(icheck==0) printf("Yes\n");
    }
return 0;
}