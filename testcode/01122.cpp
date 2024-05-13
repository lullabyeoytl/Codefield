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
        int ni=read(),s=read(),r=read();
        printf("%d",s-r);
        for(int j=1;j<=ni-2;j++){
            printf(" %d",(r+1)/(ni-1));
        }
        printf(" %d",r-(ni-2)*((r+1)/(ni-1)));
        printf("\n");
    }
}