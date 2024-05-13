#include<bits/stdc++.h>
using namespace std;
int dx[5]={0,1,0,-1,0};
int dy[5]={0,0,1,0,-1};
int r,c;
int n;
char a[60][60];
int x0;int yi;
char v[1002][5];
int vi[1002];
void dfs(int k,int x,int y)
{
    if(k>=n+1)
    {
        a[x][y]='*';
        return;
    }
    for(int t=1;x+t*dx[vi[k]]>=0&&x+t*dx[vi[k]]<n&&y+t*dy[vi[k]] >=0&&y+t*dy[vi[k]] <n;t++)
    {
        int nx=x+t*dx[vi[k]];
        int ny = y+t*dy[vi[k]];
        if(a[nx][ny]=='.')
        {
            dfs(k+1,nx,ny);
        }
    }
    return ;
}
int main()
{
    
    cin>>r>>c;
    for(int i=0;i<r;i++)
    {
        gets(a[i]);
        for(int j=0;j<c;j++)
        {
            if(a[i][j]=='*')
            {
                x0=i;
                yi=j;
            }
        }
    }
   cin>>n;
    for(int i=1;i<=n;i++)
    {
        gets(v[i]);
        if(v[i]=="NORTH")
        vi[i]=2;
        if(v[i]=="EAST")
        vi[i]=1;
        if(v[i]=="WEST")
        vi[i]=3;
        if(v[i]=="SOUTH")
        vi[i]=4;
    }
    dfs(1,x0,yi);
     for(int i=0;i<r;i++)
     {
        puts(a[i]);
     }
     system("pause");
     return 0;


}
/*
 #include<cstdio>
using namespace std;
const int MAXN=1010;
bool _map[55][55],vis[MAXN][55][55];
int to[MAXN],pos[4][2]={1,0,0,1,-1,0,0,-1};
int read(){//快读
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
void dfs(int dep,int x,int y){
	if(vis[dep][x][y]) return;
	vis[dep][x][y]=1;//记录记忆化；
	if(dep==0) return;
	while(_map[x+=pos[to[dep]][0]][y+=pos[to[dep]][1]]) dfs(dep-1,x,y);
}
int main(){//主函数
	int n=read(),m=read(),sx,sy;
	char c,s[10];
	for(int i=1;i<=n;i++){
		scanf("\n");
		for(int j=1;j<=m;j++){
			c=getchar();
			if(c=='.') _map[i][j]=1;
			if(c=='*') _map[i][j]=1,sx=i,sy=j;
		}
	}
	int k=read();
	for(int i=k;i>0;i--){
		scanf("\n%s",s);
		if(s[0]=='S') to[i]=0;
		if(s[0]=='E') to[i]=1;
		if(s[0]=='N') to[i]=2;
		if(s[0]=='W') to[i]=3;
	}
	dfs(k,sx,sy);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) printf("%c",vis[0][i][j]?'*':(_map[i][j]?'.':'X'));
		printf("\n");
	}
	return 0;
}
*/