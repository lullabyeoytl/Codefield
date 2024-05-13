#include <cstdio>
#include <algorithm>
using namespace std;
 int n,m;
int a[105];
int bp[105];
int res=0;
int dfs (int t,int sum)
{
    
    queue <int> que;
    que.push(a[1]);
    bp[1]=0;
    while(que.size())
    {
        int p =que.front();
        que.pop();
        else{
        for(int i=0;i<=1;i++)
        {

                que.push(P(nx,ny));
                bp[nx][ny]=bp[p.first][p.second]+1;
            

        }
    }
    
}
int main()
{
   scanf("%d%d",&n,&m);
   for(int i=1;i<=n;i++)
   {
    scanf("%d",&a[i]);
   }
   printf("%d",dfs(1,0));



    return 0;
}