#include <bits/stdc++.h>
using namespace std;
int n;
int a[200001],vis[200001];
int b[200001];
bool cmp(int a,int b)
{
    return a>b;
}
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
    n=read();int num=0;
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
        vis[a[i]]++;
        if(vis[a[i]]>=3)
        {
            printf("NO\n");
            return 0;
        }
        if(vis[a[i]]==2)num++;
    }
    printf("YES\n");printf("%d\n",n-num);
    sort(a+1,a+n+1);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==a[i+1])
        {
            cnt++;
            b[cnt]=a[i];
        }
        else printf("%d ",a[i]);
    }
    if(n==0)printf("\n");
    sort(b+1,b+num+1,cmp);
    if(n==0)printf("%d\n",num);
    else printf("\n%d\n",num);
    for(int i=1;i<=num;i++)
    {
        printf("%d ",b[i]);
    }
    if(num==0)printf("\n");
    return 0;

}