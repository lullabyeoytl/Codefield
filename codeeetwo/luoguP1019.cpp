#include <bits/stdc++.h>
using namespace std;
int n,m;
int sx,sy,ex,ey;
int bp[303][303];
typedef pair <int,int> P;
char ma[303][303];
int ax[300]; int ay[300]; int sizea=0;
int dx[5] = {0,1,0,-1,0};
int dy[5] = {0,0,1,0,-1};
int bfs(int x0,int y0, int x1,int y1 )
{
    memset(bp,-1,sizeof(bp));
    queue <P> que;
    que.push(P(x0,y0));
    bp[x0][y0] = 0;
    while(que.size())
    {
        P p = que.front();
        que.pop();
        if(p.first == x1&&p.second == y1)break;
        int temp = 0;int j;
         for(j=1;j<=sizea;j++)
            {
                if(p.first == ax[j] && p.second == ay[j])
                {
                    temp = 1;
                    break;
                }
            }
            if(temp)
            {
               
                
                   for(int k =1; k!=j&&k<=sizea;k++)
                   {
                    if(bp[ax[k]][ay[k]] ==-1)
                    {
                        que.push(P(ax[k],ay[k]));
                        bp[ax[k]][ay[k]] = bp[p.first][p.second];
                    }
                   }
                
        
            }
            else
            {
                 for(int i =1;i<=4;i++)
                 {
                    int nx = p.first + dx[i];int ny = p.second + dy[i];
                    if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&ma[nx][ny] != '#'&&bp[nx][ny]==-1)
                    {
                        que.push(P(nx,ny));
                        bp[nx][ny] = bp[p.first][p.second] +1;
                    }
            
                }
            }

    }
    return bp[x1][y1];
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i =1;i<=n;i++)
    {
        gets(ma[i]);
    }
    for(int i =1;i<=n;i++)
    {
        for(int j =1;j<=m;j++)
        {
            if(ma[i][j]>='A'&&ma[i][j]<='Z')
            {
                sizea+=1;
                ax[sizea] = i;ay[sizea] = j;
            }
            else if(ma[i][j]=='@')
            {
                sx = i;sy = j;
            }
            else if(ma[i][j] == '=')
            {
                ex = i; ey = j;            
            }
        }
    }


}