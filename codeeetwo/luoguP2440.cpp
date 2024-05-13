#include <cstdio>
long long int n; long long int k; 
int l,mid;
long long int min;
long long int a[100005];
long long int check (long long int t)
{ 
    long long int lo = 0; long long int hi = t;
    while(lo+1<hi)
    {
        long long int sum=0;
       mid = (lo+hi)/2;
      for(int i =1; i<= n; i++)
     {
        sum += a[i]/mid;
     }
     if(sum >=k)
     {
        lo = mid;
     }
     else
     hi = mid ;
   }
   return lo;
}
int main()
{
    scanf("%lld%lld", &n, &k);
    min = 100000001;
    for(int i = 1; i<= n; i++)
    {
        scanf("%lld", &a[i]);
        if(a[i] <= min)
        min = a[i];
    }
    printf("%lld", check(min));
    return 0;
}