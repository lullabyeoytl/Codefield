#include <bits/stdc++.h>
using namespace std;
int n,a,b;
int dp[205];//记忆化
int bp[205];//计数
int k[205];
int dx[2]={1,-1};
int bfs()
{
    memset(dp,0,sizeof(dp));
    memset(bp,-1,sizeof(bp));
    queue <int > que;
    que.push(a);
    bp[a]=0;dp[a]=1;
    while(que.size())
    {
        int fo = que.front();
        que.pop();
        if(fo==b)break;
        for(int i=0;i<=1;i++)
        {
            int nx = fo + dx[i]*k[fo];
            if(nx>=1&&nx<=n&&dp[nx]==0&&bp[nx]==-1)
            {
                que.push(nx);
                bp[nx] = bp[fo]+1;
                dp[nx] = 1;
            }
        }
    }
    return bp[b];
}

int main()
{
    scanf("%d%d%d",&n,&a,&b);
    for(int i =1;i<=n;i++)
    {
        scanf("%d",&k[i]);
    }
    printf("%d",bfs());
    return 0;
}

