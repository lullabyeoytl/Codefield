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
int ver[200005];int edge[200005];
int nxt[200005],head[1000000009];int tot;
void add(int x,int y,int z)//加入有向边（x,y),权值为z
{

    ver[++tot]=y;edge[tot]=z;
    nxt[tot]=head[x];head[x]=tot;//在表头x处插入

}
int main(){
    int n=read();int q=read();
    for(int i=1;i<=q;i++){
        int ti=read(),ai=read(),bi=read();
        if(ti==1){
            int icheck=0;
            for(int j=head[ai];j;j=nxt[j]){
                int y = ver[j];  
                if(y==bi)icheck=1;
            }
            if(icheck)continue;
            else add(ai,bi,1);
        }
        if(ti==2){
            int icheck=0;
            for(int j=head[ai];j;j=nxt[j]){
                int y = ver[j];  
                if(y==bi){
                    edge[j]=0;
                    icheck=1;
                }

            }
            if(!icheck)add(ai,bi,0);
        }
        if(ti==3){
            int icheck=0;
            for(int j=head[ai];j;j=nxt[j]){
                int y = ver[j];
                int z=edge[j];
                if(y==bi&&z==1){
                    for(int o=head[bi];o;o=nxt[o]){
                         int y = ver[j];
                        int z=edge[j];
                        if(y==ai&&z==1){
                            icheck=1;
                            break;
                            }
                    }
                }
                if(icheck){
                    printf("Yes\n");
                    break;
                    }
            }
            if(!icheck)printf("No\n");
        }
    }

}