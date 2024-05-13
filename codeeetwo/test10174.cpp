/*
#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch =getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch =='-')
        f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}

int a[100005];
long long s[100005];
double mid;
int main()
{
    int n,m;s[0]=0;
    n=read();
    m=read();
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
        a[i] *= 1000; 
        s[i] = s[i-1]+a[i];
    }
    int maxn = -1;
    for(int i = m;i<=n;i++)
    {
        for(int j = 1;j<=n-i+1;j++)
        {
            if(maxn<= (s[j+i-1]-s[j-1])/ i)
             maxn = (s[j+i-1]-s[j-1])/ i;
        }
    }
    printf("%d",maxn);
    return 0;
    
    
}

*/
#include<bits/stdc++.h>
using namespace std;
long long n,m,Max;
long long a[100005],s[100005];
inline int read()
{
    int x=0,f=1;
    char ch =getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch =='-')
        f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
int main()
{
    n=read();
    m=read();
    for (int i=1;i<=n;i++) 
    {
        a[i]=read();
        a[i]*=10000;
        Max=max(Max,a[i]);
    }
    int lo=0,hi=Max;
    while (lo<=hi) 
    {
        bool ok=0;
        long long mid=(lo+hi)/2,Min=0;
        for (int i=1;i<=n;i++) {
            s[i]=s[i-1]+(a[i]-mid); //s[i]为a[i]减掉mid之后的前缀和
            if (i>=m) {
                Min=min(Min,s[i-m]);
                if (s[i]>Min) { //判断是否平均值能>=mid
                    ok=1;
                    break;
                }
            }
        }
        if (ok) lo=mid+1;
        else hi=mid-1;
    }
    cout<<(lo/10)<<endl;
    return 0;
}
