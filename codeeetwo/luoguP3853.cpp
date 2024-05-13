#include <cstdio>
int l,n,k,mid;
int a[100005];
int check()
{
    int add = 0;
    for(int i =2; i<=n; i++)
     {
        add += (a[i]-a[i-1]-1)/mid;
     }
     if(add <= k)
     return 1;
     else
     return 0;
}
int main()
{
    scanf("%d%d%d", &l,&n,&k);
    int max = -1;
    for(int i =1; i<= n ;i++)
    {
        scanf("%d", &a[i]);
        if(i != 1)
        {
            if(a[i] - a[i-1] >= max)
            max = a[i] - a[i-1];
        }
    }
    int lo = 1; int hi = max;
    while (lo < hi)
    {
        mid = (lo +hi) / 2;
        if(check())
        hi = mid;
        else
        lo = mid+1;
    }
    printf("%d", lo);
    return 0;
}