#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
int v;int g;
int need[30];
int have[20][30];
int nowhave[30];
int res;
int mid;
void dfs(int having[],int k,int oknum,int xsum)
{
    if(k>=v+1)
    return ;
    else if(oknum>=v)
    {
        if(xsum<=mid)
        {
            res++;
        }
        return ;
    }
    else
    {
        for(int i=0;i<=1;i++)
        {
            for(int j=1;j<=v;j++)
            {
                having[j] += have[k][j]*i;
                xsum+=i;
                if(having[j]>=need[j]&&having[j]-have[k][j]<need[j])
                {
                    oknum+=1;
                }
            }
            dfs(having,k+1,oknum,xsum);
        }
    }
}
int main()
{
    scanf("%d",&v);
    for(int i=1;i<=v;i++)
    {
        scanf("%d",&need[i]);
    }
    scanf("%d",&g);
    for(int i=1;i<=g;i++)
    {
        for(int j=1;j<=v;j++)
        {
            scanf("%d",&have[i][j]);
        }
    }
    int lo=1;int hi=v;
    while(lo<hi)
    {
        memset(nowhave,0,sizeof(nowhave));
        int res=0;
        mid = (hi+lo)/2;
        dfs(nowhave,1,0,0);
        if(res>0)hi=mid;
        else lo=mid+1;
    }
    printf("%d",lo);
    system("pause");
    return 0;
}