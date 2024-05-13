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
    long long n;
    cin>>n;
    int dig[25];
    int x=n;
    n=n-1;
    int cnt=0;
    while(n>0){
        cnt++;
        dig[cnt]=n-(n/5)*5;
        dig[cnt]*=2;
        n/=5;
    }
    if(x==1)printf("0");
    else{
    for(int i=cnt;i>=1;i--)printf("%d",dig[i]);
    }
}