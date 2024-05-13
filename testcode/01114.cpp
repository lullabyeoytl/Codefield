#include <bits/stdc++.h>
using namespace std;
int a[401][401];
typedef pair<int ,int> P;
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
vector <P> ve;
int n,m;
int sqche(int x)
{
    if((int)sqrt(x)*(int)sqrt(x)!=x) return 0;
    else return 1;
}
void spa()
{
    for(int i=0;i*i<=m/2;i++)
    {
        if(sqche(m-i*i))
        {
            ve.push_back(make_pair(i,(int)sqrt(m-i*i)));
        }
    }
}
int main()
{
    n=read();m=read();
    spa();
    memset(a,-1,sizeof(a));
    queue <P> q;
    q.push(make_pair(1,1));
    a[1][1]=0;
    while(q.size())
    {
        P to=q.front();
        q.pop();
        for(int i=0;i<ve.size();i++)
        {
            int dx[8]={ve[i].first,-ve[i].first,ve[i].second,-ve[i].second,ve[i].first,-ve[i].first,ve[i].second,-ve[i].second};
            int dy[8]={ve[i].second,ve[i].second,ve[i].first,ve[i].first,-ve[i].second,-ve[i].second,-ve[i].first,-ve[i].first};
            for(int j=0;j<8;j++)
            {
                int x=to.first+dx[j];int y=to.second+dy[j];
                if(x>=1&&x<=n&&y>=1&&y<=n&&a[x][y]==-1)
                {
                    a[x][y]=a[to.first][to.second]+1;
                    q.push(make_pair(x,y));
                }
            }
        }
        
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    
}