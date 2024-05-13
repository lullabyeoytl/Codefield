#include <bits/stdc++.h>
using namespace std;
int dpmin[202][202],dpmax[202][202];
int a[202],s[202];
int main()
{
    int n;
    scanf("%d",&n);
    memset(dpmin,0x3f,sizeof(dpmin));
    memset(dpmax,0,sizeof(dpmax));
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i+n]=a[i];
    }
    for(int i=1;i<=2*n;i++)
    {
        s[i]=s[i-1]+a[i];
        dpmax[i][i]=0;
        dpmin[i][i]=0;
    }
    for(int len=2;len<=n;len++)
    {
        for(int l=1;l<=2*n-len+1;l++)
        {
            int r=l+len-1;
            for(int k=1;k<r;k++)
            {
                dpmin[l][r]=min(dpmin[l][r],dpmin[l][k]+dpmin[k+1][r]);
              
                dpmax[l][r]=max(dpmax[l][r],dpmax[l][k]+dpmax[k+1][r]);
                
            } 
             dpmin[l][r] += s[r]-s[l-1];dpmax[l][r]+=s[r]-s[l-1]; 
        }
    
    }int minn=dpmin[1][n];int maxn=dpmax[1][n];
    for(int i=1;i<=n;i++)
    {
        minn=min(dpmin[i][i+n-1],minn);
        maxn = max(dpmax[i][i+n-1],maxn);
    }
    printf("%d\n",minn);
    printf("%d\n",maxn);
    system("pause");
    return 0;
}