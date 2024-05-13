#include <bits/stdc++.h>
using namespace std;
int p[1003];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&p[i]);
    }
    int maxn = 0;
    for(int i = 1,bg=1;i<=n;i++)
    {
        if(i==1)continue;
        else
        {
            if(p[i]>p[i-1])
            {
                if(p[i]-p[bg]>=maxn)maxn = p[i]-p[bg];
            }
            else
            {
                bg = i;
            }
        }
    }
    printf("%d",maxn);

    return 0;
}