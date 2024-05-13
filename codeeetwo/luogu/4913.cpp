#include <bits/stdc++.h>
using namespace std;
struct tree{
    int lo;
    int ri;
    int dep;
}tres[1000006];
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
    tres[1].dep=1;
    int n = read();
    for(int i=1;i<=n;i++)
    {
        tres[i].lo = read();
        tres[i].ri = read();
        tres[tres[i].lo].dep=tres[i].dep+1;
        tres[tres[i].ri].dep=tres[i].dep+1;
    }
    int maxn=1;
    for(int i=1;i<=n;i++)
    {
        maxn=max(maxn,tres[i].dep);
    }
    printf("%d",maxn);
    system("pause");
    return 0;
}