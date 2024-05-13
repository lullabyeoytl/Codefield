#include <cstdio>
#include <cmath>
long double w0,w; int m;
long double mid;
int main()
{
    scanf("%Lf%Lf%d", &w0,&w,&m);
   long double sta = w0/w;
   long double lo = 0;   long double hi = 1/sta;  
   while(lo<hi-0.00000001)
   {
      mid= (lo + hi) / 2;
      if((1/mid)  * (1-(1/pow(1+mid , m))) >= sta)
      {
        lo = mid;
      }
      else
      hi = mid;
   }
   long double res = 100*lo;
   printf("%.1Lf", res);
   getchar();
   getchar();
   getchar();
   return 0;
}
