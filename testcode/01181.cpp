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
int a[104];
int main(){
    int n=read(),k=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    if(k>=n){
        for(int i=1;i<=n-1;i++)printf("0 ");
        printf("0");
    }
    else{
        for(int i=k+1;i<=n;i++){
            printf("%d ",a[i]);
        }
        for(int i=1;i<=k-1;i++)printf("0 ");
        printf("0");
    }
}