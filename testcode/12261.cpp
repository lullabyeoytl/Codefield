/*
#include <cstdio>
#include <bits/stdc++.h>
#include <utility>
bool vis[200005];
using namespace std;
priority_queue <pair<int, pair<int,int> > >que;
int sc[200005]; char ge[200005];
int dan[100005][2];
typedef pair<int, pair<int,int> > P;
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
    int n=read();
    for(int i=1;i<=n;i++)
    {
        scanf("%c",&ge[i]);
    }
    for(int i=1;i<=n;i++)
    {
        sc[i]=read();
        if(i>=2)
        {
            if(ge[i]!=ge[i-1])
            {
                que.push( make_pair(-abs(sc[i]-sc[i-1]),make_pair(i-1,i)));
            }
        }
    }
    int cnt=0;
    while(que.size())
    {
        P to =que.top();
        que.pop();
        int x=to.second.first;int y=to.second.second;
        if(vis[x]==0&&vis[y]==0)
        {
            cnt++;
            dan[cnt][0]=x;dan[cnt][1]=y;
            vis[x]=vis[y]=1;
            if(x!=1&&y!=n&&vis[x-1]!=1&&vis[y+1]!=1&&ge[x-1]!=ge[y+1])
            {
                que.push( make_pair(-abs(sc[x-1]-sc[y+1]),make_pair(x-1,y+1)));
            }
        }
    }
    printf("%d",cnt);
    for(int i=1;i<=cnt;i++)
    {
        printf("\n%d %d",dan[i][0],dan[i][1]);
    }
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
#define inf 2000000000
int ans[200005][2],sum=0;
struct node
{
	int l,r,cha,xu;
	bool judge;
}a[200005];

bool operator<(node rr,node ll)
{
	int lll=abs(ll.cha),rrr=abs(rr.cha);
	if(rrr!=lll)
		return lll<rrr;
	else
		return ll.xu<rr.xu;
}

priority_queue <node> que;

int main ( )
{
	int n,now,next,t=0;
	char x;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if(x=='B') a[i].judge=0;
		else a[i].judge=1;
	} 
	scanf("%d",&now);
	for(int i=1;i<n;i++)
	{
		scanf("%d",&next);
		a[i].xu=i;	 
		a[i].cha=next-now;
		a[i].l=i-1;a[i].r=i+1; 
		que.push(a[i]);
		now=next;
	}
	a[n].r=n+1;a[n].xu=n;a[n].cha=inf;
	while(!que.empty())
	{
		int xx=que.top().xu,cmp=que.top().cha;
		que.pop();
		int yy=a[xx].r;
		if(a[xx].cha==cmp&&a[xx].judge!=a[yy].judge&&xx!=0&&yy!=n+1)
		{
			ans[++t][0]=xx;ans[t][1]=yy;
			a[a[xx].l].cha+=a[xx].cha+a[yy].cha;
			a[a[yy].r].l=a[xx].l;a[a[xx].l].r=a[yy].r;
			if(a[xx].l>0&&a[yy].r<=n)
				que.push(a[a[xx].l]);
			a[xx].l=a[xx].r=0;a[yy].l=a[yy].r=n+1;
		}
	}
	printf("%d\n",t);
	for(int i=1;i<=t;i++)
		printf("%d %d\n",ans[i][0],ans[i][1]);
	return 0;
}