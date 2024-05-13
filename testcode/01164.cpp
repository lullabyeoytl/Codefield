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
int a[200005];
int su[200005];
int main(){
    int t=read();
    for(int i=1;i<=t;i++){
        int n=read();int k=read();
        string s;
        memset(a,0,sizeof(a));
        memset(su,0,sizeof(s));
        getline(cin,s);
        for(int j=0;j<n;j++){
            if(s[j]=='B')a[j+1]=1;
            su[j+1]=su[j]+a[j+1];
        }
        int lo=1,hi=k;int minn=n+1;
        while(hi<=n){
            int sum_n=su[hi]-su[lo-1];
            minn=min(k-sum_n,minn);
            lo++;hi++;
        }
        printf("%d\n",minn);
    }
}