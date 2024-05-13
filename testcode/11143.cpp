#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[101][11];
int dfs(int t)
{
    int dig[101]={0};
    int cnt=m;
    int jtemp=t;
    while(jtemp>0)
    {
        if(jtemp%2==1)
        dig[cnt]=1;
        jtemp/=2;
        cnt--;
    }
}
int main()
{
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    system("pause");
    return 0;
}