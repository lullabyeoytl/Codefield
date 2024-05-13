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
    for(int i=1;i<=n;i++){
        int ni=read();
        if(ni%3==0)printf("%d %d %d\n",ni/3,ni/3+1,ni/3-1);
    if(ni%3==1)printf("%d %d %d\n",ni/3,ni/3+2,ni/3-1);
    if(ni%3==2)printf("%d %d %d\n",ni/3+1,ni/3+2,ni/3-1);
    }
    
}