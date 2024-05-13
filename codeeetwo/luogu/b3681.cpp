#include <cstdio>
#include <iostream>
int n,u[1000006];
long long a[1000006];
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
    n=read();
    for(int i=2;i<=n;i++)
    {
        u[i]=read();
    }
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
    }
    for(int i=n;i>=2;i--)
    {
        a[u[i]]+=a[i];
    }
    for (int i = 1; i < n; ++i)
	std::cout << a[i] << ' ';
    std::cout <<a[n];
    return 0;
}