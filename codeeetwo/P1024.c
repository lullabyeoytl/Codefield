#include <stdio.h>
double a,b,c,d;
double x[8];
double f(double t)
{
    return a*t*t*t + b*t*t +c*t + d; 
}
int main(void)
{
    scanf("%lf%lf%lf%lf", &a,&b,&c,&d);int s =1;
    for(double i = -100; i<=100; i++)
    {
        if(f(i)*f(i+1) < 0)
        {
            x[2*s-1] = i;x[2*s] = i+1;
            s++;  
        }
    }//得到x1 to x6;
    for(int j =1 ; j<=3 ; j++)
    {
        while(x[2*j] - x[2*j-1] >0.001 )
        {
            double t = (x[2*j-1] + x[2*j])/2.000;
            if(f(x[2*j-1])* f(t) < 0)
            {
                x[2*j] = t;
            }
            else
            x[2*j-1] = t;
        }
        printf("%.2lf ",x[2*j]);
    }
    return 0;
}