#include <bits/stdc++.h>
using namespace std;
int n,m,icheck;;
int fa[101][101];
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
    int n=read();
    if(n==2)
    {
        int x=read(),y=read();
        if((x-y)%2==1)
        {
            printf("-1");
        }
        else printf("%d",x+y);
    }
    else
    {
        priority_queue <int> que;
        for(int i=1;i<=n;i++)
        {
            int y=read();
            que.push(y);
        }
        long long sum1=0,sum2=0;
        while(que.size())
        {
            int to1=que.top();
            que.pop();
            int to2=que.top();
            que.pop();
            if((to1-to2)%2==0)printf("%d",to1+to2);
            else
            {
                int to3=que.top();
                que.pop();
                if(to3%2==to1%2)
                {
                    sum1=to3+to1;
                    while(que.size()){
                    while(que.top()%2!=to2)
                    {
                        que.pop();
                    }
                    }
                    sum2=to2+que.top();
                }
                if(to3%2==to2%2)
                {
                    sum1=to3+to2;
                    while(que.size()){
                    while(que.top()%2!=to1)
                    {
                        que.pop();
                    }
                    }
                    sum2=to1+que.top();
                }
            }
        }
        if(que.empty()) printf("%lld",sum1);
        else
        {
            printf("%lld",(sum1>sum2)?sum1:sum2);
        }
    }
}
