#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[2005][2005];
int gcd(int a1,int a2)
{
    if(a1==a2)
    return a1;
    else
    {
        gcd(a1,abs(a1-a2));
    }
}
int main()
{
    int n,m,x0,y0;
    scanf("%d%d",&n,&m);
    int gdd;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
            if(i==1&&j==1)
            {
                gdd=a[i][j];
            }
            else
            {
                gdd =gcd(gdd,a[i][j]);
            }
        }
    }
    scanf("%d%d",&x0,&y0);
    if(gdd!=1)printf("-1");
    else
    {
        
    }

    system("pause");
    return 0;
}