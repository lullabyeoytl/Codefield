#include <bits/stdc++.h>
using namespace std;
long long mid;
int main()
{
    long long n;
    scanf("%lld",&n);
    long long lo = 1; long long hi = 100000;
    while(lo<hi) 
    {
        mid = (hi+lo)/2;
        if(mid*mid*mid>=n)hi = mid;
        else lo = mid+1;
    }
    if(lo*lo*lo<=n)
    printf("%lld",lo);
    else
    printf("%lld",lo-1);
    return 0;
}