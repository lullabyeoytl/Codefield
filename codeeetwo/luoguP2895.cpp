#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
int m;int x[50004];int y[50004];int t[50004];
int bp[303][303];
int resmin[303][303];//res[x][y]赋值为最小的ti;
int dx[5]={0,1,0,-1,0}; int dy[5] = {0,0,1,0,-1};
int bfs()
{
    memset(bp,-1,sizeof(bp));
    queue <P> que;
    que.push(P(0,0));
    bp[0][0]=0;
    while(que.size())
    {
        P p = que.front();que.pop();
        if(resmin[p.first][p.second] == -1)
        {
            printf("%d",bp[p.first][p.second]);
            return 0;
        }
        
        for(int i =1;i<=4;i++)
        {
            int nx = p.first + dx[i];int ny = p.second + dy[i];
            if(nx>=0&&nx<=300&&ny>=0&&ny<=300&&resmin[nx][ny]>=(bp[p.first][p.second]+2)&&bp[nx][ny]==-1)
            {
                que.push(P(nx,ny));
                bp[nx][ny] = bp[p.first][p.second]+1;
            }
        }
    }
    printf("-1");
    return 0;
}

int main()
{
    scanf("%d",&m);
    memset(resmin,-1,sizeof(resmin));
    for(int i =1;i<=m;i++)
    {
        scanf("%d%d%d",&x[i],&y[i],&t[i]);
        if(resmin[x[i]][y[i]]==-1)
        resmin[x[i]][y[i]]=t[i];

        if(resmin[x[i]+1][y[i]]==-1)
        resmin[x[i]+1][y[i]]=t[i];

       if(resmin[x[i]][y[i]+1]==-1)
        resmin[x[i]][y[i]+1]=t[i];

       if( x[i]>0&&resmin[x[i]-1][y[i]]==-1)
        resmin[x[i]-1][y[i]]=t[i];

       if(y[i]>0&&resmin[x[i]][y[i]-1]==-1)
        resmin[x[i]][y[i]-1]=t[i];
    }
   bfs();
    return 0;

}
