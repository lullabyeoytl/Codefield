#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 200005
int n, m, d;
int first[N], Next[N], to[N], sp[N], len[N], tot;
double dis[205][1005];
int vis[205][1005];
pair<int, int> from[205][1005];
void add(int x, int y, int z, int zz)
{
	Next[++tot] = first[x];
	first[x] = tot;
	to[tot] = y;
	sp[tot] = z;
	len[tot] = zz;
	return;
}
void dijkstrar(int x)
{
	priority_queue<pair<double, pair<int, int> > > q;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= 505; j++)
		{
			dis[i][j] = 1e9;
			vis[i][j] = 0;
		}
	}
	dis[x][70] = 0;
	q.push(make_pair(0, make_pair(x, 70)));
	while(!q.empty())
	{
		pair<int, int> u = q.top().second;
		q.pop();
		if(vis[u.first][u.second])
		{
			continue;
		}
		vis[u.first][u.second] = 1;
		for(int i = first[u.first]; i; i = Next[i])
		{
			int v = to[i], sped = (sp[i] ? sp[i] : u.second);
			double time = (double)len[i] / (double)sped;
			if(dis[u.first][u.second] + time < dis[v][sped])
			{
				dis[v][sped] = dis[u.first][u.second] + time;
				from[v][sped] = u;
				q.push(make_pair(-dis[v][sped], make_pair(v, sped)));
			}
		}
	}
	return;
}
void write(int x, int v)
{
	if(x == 1)
	{
		printf("0 ");
		return;
	}
	write(from[x][v].first, from[x][v].second);
	printf("%d ", x - 1);
	return;
}
signed main()
{
	scanf("%d%d%d", &n, &m, &d);
	int x, y, z, zz;
	for(int i = 1; i <= m; i++)
	{
		scanf("%d%d%d%d", &x, &y, &z, &zz);
		x++;
		y++;
		add(x, y, z, zz);
	}
	dijkstrar(1);
	d++;
	int maxx = 0;
	dis[d][maxx] = 1e9;
	for(int i = 1; i <= 500; i++)
	{
		if(dis[d][i] < dis[d][maxx])
		{
			maxx = i;
		}
	}
	write(d, maxx);
	return 0;
}
//dj算法的思想，不断轮，只要改变最短的定义就行
