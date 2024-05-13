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
int s[200005],f[200005];
int main(){
    queue <int> q_work;
    queue <int> q_stay;
    int n=read();
    for(int i=1;i<=n;i++){
        int ni=read();
        memset(s,0,sizeof(s));
        memset(f,0,sizeof(f));
        for(int i=1;i<=ni;i++)
        {
            s[i]=read();
        }
         for(int i=1;i<=ni;i++)
        {
            f[i]=read();
        }
        q_work.push(1);int tbg=s[1];int il=1;
        while(q_work.size()){
            int to=q_work.front();
            q_work.pop();
            printf("%d ",f[to]-tbg);
            while(s[il+1]<=f[to]&&il+1<=ni){
                il++;
                q_work.push(il);
            }
            tbg=f[to];
            if(il!=ni&&q_work.size()==0){
                tbg=s[il+1];
                il++;
                q_work.push(il);
            }
        }
        printf("\n");
    }
}