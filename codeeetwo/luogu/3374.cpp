#include <bits/stdc++.h>
using namespace std;
int t[500005];
int a[500005];
int n;
void add(int x,int y)
{
    for( ; x<=n;x+=x&-x)t[x]+=y;
}
int ask(int x,int y)
{
    x-=1;
    int ans1=0;int ans2=0;
    for( ;x;x-=x&-x)
    {
        ans1+=t[x];
    }
    for( ;y;y-=y&-y)
    {
        ans2+=t[y];
    }
    return ans2-ans1;
}
int main()
{
    int m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        add(i,a[i]);
    }
    for(int i=1;i<=m;i++)
    {
        int op,x,y;
        scanf("%d%d%d",&op,&x,&y);
        if(op==1)
        {
            add(x,y);
        }
        else
        {
            printf("%d\n",ask(x,y));
        }
    }
    system("pause");
    return 0;
}
