#include <bits/stdc++.h>
using namespace std;
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
    int n=read();
    long long sum=0;
    for(int i=1;i<=n;i++){
        int x=read();
        sum+=x;
    }
    printf("%lld",sum);
    return 0;

}