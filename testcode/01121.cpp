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
 string pi="3141592653589793238462643383279";
 int compare(string a,int x){
    if(a[x]==pi[x]) return compare(a,x+1);
    else return (x);
 }
int main(){
    int n=read();
    for(int i=1;i<=n;i++){
        string st;
        getline(cin,st);
        printf("%d\n",compare(st,0));
    }

}