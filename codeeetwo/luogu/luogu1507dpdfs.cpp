#include <bits/stdc++.h>
using namespace std;
int n,hmax,tmax;
int hi[55];
int ti[55];
int ki[55];
int kmaxn=0;
int dfs(int num,int h,int t,int k)
{
    if(num>=n+1)
    {
        return kmaxn=max(kmaxn,k);
    }
    if(h>hmax||t>tmax)
    {
        return 0;
    }
    for(int i=1;i>=0;i--)
    {
       if(h+i*hi[num]>hmax||t+i*ti[num]>tmax)//及时剪枝
        continue;
        else
        {
            h+=i*hi[num];t+=i*ti[num];
            dfs(num+1,h,t,k+ki[num]*i);
            h-=i*hi[num];t-=i*ti[num];//回溯使其他搜索正常进行，这个写法还不如dfs里加不改htk的值
        }
    
    }
    return kmaxn;
}

int main()
{
    scanf("%d%d",&hmax,&tmax);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&hi[i],&ti[i],&ki[i]);
    }
    printf("%d",dfs(1,0,0,0));
    system("pause");
    return 0;
}
