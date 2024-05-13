#include<bits/stdc++.h>
using namespace std;
struct goods
{
    mutable int a,b,c;
    bool operator<(const goods &B)const{
        if(a==B.a){
            return b>B.b;
        }
        return a>B.a;
    }
}w[100010];

bool cmp(goods a,goods b){
    return a.b<b.b;
}

long long n,x,ans,maxn;
int main()
{
    scanf("%lld%lld",&x,&n);
    priority_queue<goods> q;
    for(int i=1;i<=n;i++){
        scanf("%lld%lld%lld",&w[i].a,&w[i].b,&w[i].c);
        maxn=(maxn>w[i].b)?maxn:w[i].b;
    }
    sort(w+1,w+1+n,cmp);
    int top=n;
    for(int i=x;i;i--){
        while(w[top].b>=i){
            q.push(w[top]);
            --top;
        }
        ans+=q.top().a;
        q.top().c--;
        if(!q.top().c)
        {
            q.pop();
        }
    }
    printf("%lld",ans);
    return 0;
}