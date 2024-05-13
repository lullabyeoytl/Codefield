#include<bits/stdc++.h> 
using namespace std;
typedef pair<int,int> pp;
deque<pp> q;
int n,m,ans=0; 
int a[105][105]; 
bool used[105][105]; 
int dx[4]={-1,1,0,0}; 
int dy[4]={0,0,-1,1};
void bfs(int sx,int sy) 
{
	pp st;
	st.first==sx;st.second=sy;
	used[sx][sy]=1;
	q.push_back(st);
	while(!q.empty())
	{
		pp nw=q.front();
		for(int i=0;i<4;i++)
		{
			pp nxt=nw;
			nxt.first+=dx[i];
			nxt.second+=dy[i];
			if(a[nxt.first][nxt.second]==0 || used[nxt.first][nxt.second]==1) continue;
			used[nxt.first][nxt.second]=1;
		}
		q.pop_front();
	}
}
int main()
{
	cin>>n>>m;
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) 
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]!=0)
			{
                used[i][j]=1;
			    bfs(i,j);
			    ans++;
			}
		}
	}
	cout<<ans;	
    return 0;
}