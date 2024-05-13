#include <cstdio>
long long n ;long long m; long long a[1000006];
long long mid;
long long check(long long t)
{
    long long lo = 0; long long hi = t;
    while(lo < hi)
    {
        mid = (lo+hi)/2;
        long long sum = 0;
        for(int i = 1; i<= n; i++)
        {
            if(mid >= a[i])
            continue;
            else
            sum += a[i] - mid;
        }
        if(sum >= m)
        lo = mid;
        else
        hi = mid -1;
    }
    return lo;
}
int main()
{
    scanf("%lld%lld", &n, &m);
    int max = -1;
    for(int i = 1; i<= n;i++)
    {
        scanf("%lld", &a[i]);
        if(a[i]>=max)
        max = a[i];
    }
    long long h = check (max);
    printf("%lld", h);
    return 0;
}