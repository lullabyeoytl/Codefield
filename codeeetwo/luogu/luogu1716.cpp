#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};
string s;
int n,cnt,l[510],a[550][550];
void bfs(int x,int y)
{
    queue< pair<int,int> >q;	
    q.push(make_pair(x,y));
    a[x][y]=0;
    while(!q.empty())
    {
        int cx=q.front().first;		
        int cy=q.front().second;	
        q.pop();	
        for(int i=0;i<4;i++)
        {
            int nx=cx+dx[i];
            int ny=cy+dy[i];	
            if(nx>=1 && nx<=n && ny>=1 && ny<=l[nx] && a[nx][ny]==1)
            {
                a[nx][ny]=0;	
                q.push(make_pair(nx,ny));	
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    getline(cin,s);
    for(int i=1;i<=n;i++)
    {
        getline(cin,s);
        l[i]=s.length();
        for(int j=1;j<=l[i];j++)
        {
        	if(s[j-1]>='a' && s[j-1]<='z')
                a[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=l[i];j++)
        {
            if(a[i][j]==1)	
            {
                bfs(i,j);	
                cnt++;	
            }
        }
    printf("%d\n",cnt);
    return 0;
} 