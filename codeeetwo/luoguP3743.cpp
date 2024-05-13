#include <cstdio>
#include <cstdlib>
int n; double p;
double a[100005] , b[100005];
double mid;
int main()
{
    scanf("%d%lf", &n, &p);
    double sum1 = 0;double sum2 = 0;
    for(int i = 1; i<= n; i++)
    {
        scanf("%lf%lf", &a[i], &b[i]);
        sum1 += a[i] ;
        sum2 += b[i];

    }
    if(p >= sum1)printf("-1");
    else
    {
        double lo = 0; double hi = 100000000 ; 
        while (lo < hi -0.000001)
        {
            mid = (lo + hi) / 2; double tsum = 0;
            for(int i = 1; i<= n; i++)
            {
                if (b[i] - mid * a[i] >= 0)
                continue;
                else
                tsum += (mid * a[i] - b[i]) /(double)p;

            }
            if(tsum >= mid )
            hi = mid;
            else 
            lo = mid;
        }
        printf("%lf", hi);
    }
    return 0;
}