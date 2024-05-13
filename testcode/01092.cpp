#include <bits/stdc++.h>
using namespace std;
int n;
int ji[2001],ou[2001];
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
    n=read();int jsum=0,osum=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        x=read();
        if(x%2==1)
        {
            jsum++;
            ji[jsum]=x;
        }
        else
        {
            osum++;
            ou[osum]=x;
        }
    }
    if(abs(jsum-osum)<=1)printf("0");
    else
    {
        if(jsum>osum)
        {
            sort(ji+1,ji+jsum+1);
            long long sum=0;
            for(int i=1;i<=abs(jsum-osum)-1;i++)
            {
                sum+=ji[i];
            }
            printf("%lld",sum);
        }
        if(jsum<osum)
        {
            sort(ou+1,ou+osum+1);
            long long sum=0;
            for(int i=1;i<=abs(jsum-osum)-1;i++)
            {
                sum+=ou[i];
            }
            printf("%lld",sum);
        }
    }
    return 0;
}