#include <bits/stdc++.h>
using namespace std;
int n,m;
int fa[101][101];
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
int ucheck()
{
    int lsum=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int k=1;k<=m;k++)
            {
                if(fa[k][i]==1&&fa[k][j]==1)
                {
                    lsum+=1;
                    break;
                }
                else continue;
            }
        }
    }
    if (lsum==(n*(n-1))/2) return 1;
    else return 0;
}
int main(){
    n=read(), m=read();
    for(int i=1;i<=m;i++)
    {
        int ki=read();
        for(int j=1;j<=ki;j++)
        {
           int y=read();
           fa[i][y]=1;
        }
    }
    if(ucheck())
    printf("Yes");
    else printf("No");
}