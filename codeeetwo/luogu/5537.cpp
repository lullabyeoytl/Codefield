#include <bits/stdc++.h>
using namespace std;
vector <int> son[500005];
int s_num[500005];
int a[500005];
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
void tree_build(int n){
    for(int i=1;i<=n;i++){
        int x=read();
        if(x!=0)s_num[x]++;
        son[x].push_back(i);
    }
}

void cor(int now,int y,int l,int r){
    if(a[y]>s_num[now]||y==r){
        printf("%d\n",now);
        return ;
    }
    else{
        cor(a[y],y+1,l,r);
    }
}

int main(){
    int n=read(),m=read(),q=read();
    tree_build(n);
    for(int i=1;i<=m;i++)a[i]=read();
    for(int i=1;i<=q;i++){
        int op;
        scanf("%d",op);
        if(op==1){
            int x,l,r;
            scanf(" %d %d %d",x,l,r);
            cor(x,l,l,r);
        }
        if(op==2){
            int t,k;
            scanf(" %d %d",t,k);
            a[t]=k;
        }
    }
    return 0;
}