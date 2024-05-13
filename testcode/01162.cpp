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
priority_queue <int> a;

priority_queue <int> b;
int main(){
    int t=read();
    for(int i=1;i<=t;i++){
        int ni=read();
        while(a.size())a.pop();
        while(b.size())b.pop();
        for(int j=1;j<=ni;j++)
        {
            int num=read();
            a.push(num);
        }
        for(int k=1;k<=ni;k++){
            int num=read();
            b.push(num);
        }
        int stad=a.top()-b.top();
        if(stad<0){
            printf("NO\n");
            continue;
        }
        while(a.top()-b.top()==stad||(b.top()==0&&a.top()<=stad)){
            a.pop();
            b.pop();
            if(a.empty())break;
        }
        if(a.empty())printf("YES\n");
        else printf("NO\n");
    }
}