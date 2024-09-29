#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

template<typename T>
inline T read()
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
    int n=read<int>();
    int q=read<int>();
    int a[n+1];
    long long all_lenght=0;
    for(int i=1;i<=n;i++){
        a[i]=read<long long>();
        all_lenght+=a[i];
    }
    cout<<all_lenght<<endl;
    for(int i=1;i<=q;i++){
        long long l=read<long long>();
        all_lenght+=l;
        cout<<all_lenght<<endl;
    }
    return 0;
}