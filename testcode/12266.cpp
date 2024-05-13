#include <algorithm>
#include <utility>
#include <cstring>
#include <cstdio>
#include <queue>
int n,m,k;
std:: priority_queue<int,std::vector<int>,std::greater<int> >q;
int a[801][801];//nhangmlie
int tempnum[640001];
void emerge(int x)
{
    if(x==n+1)
    {
        for(int i=1;i<=k;i++)
        {
            int to=q.top();
            q.pop();
            printf("%d ",to);
        }
        return ;
    }
    else
    {
        memset(tempnum,0,sizeof(tempnum));
        int cnt=0;
        while(q.size())
        {
            int to=q.top();
            q.pop();
            for(int i=1;i<=m;i++)
            {
                cnt++;
                tempnum[cnt]=to+a[x][i];
            }
        }
        std::sort(tempnum+1,tempnum+cnt+1);
        if(cnt>k)
        {
            for(int i=1;i<=k;i++)
            {
                q.push(tempnum[i]);
            }
        }
        else
        {
            for(int i=1;i<=cnt;i++)
            {
                q.push(tempnum[i]);
            }
        }
        emerge(x+1);
    }
    
}
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
int main()
{
    n=read();m=read();k=read();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            a[i][j]=read();
        }
    }
    for(int i=1;i<=m;i++)
    q.push(a[1][i]);
    emerge(2);
    return 0;
}