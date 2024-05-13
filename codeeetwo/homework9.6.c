#include <stdio.h>
#define N 10000000
double f1(double x)
{
    return (1+x*x);
}
double f2(double x)
{
    return (x/(1+x*x));
}
double Integral(double (* f)(double), double a,double b)//f后为什么要接一个double
{
      double sum = 0;
      for(int i = 0;i<=N-1;i++)
      {
        sum += f(a+(i*(b-a))/(double)N);
      }
      return (sum *(b-a))/(double)N ;
}
int main()
{
    double res1,res2;
    res1 =Integral(*f1, 0,1);
    res2 = Integral(* f2, 0, 3);
    printf("%lf\n",res1);
    printf("%lf\n",res2);
    return 0;
}