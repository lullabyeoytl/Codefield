#include <stdio.h>
#include <math.h>
int main(void)
{
    double s,x;
    scanf("%lf %lf" , &s , &x);
    double length = 0;
    for(int n= 1; ;n++)
    {
        if (length < s-x)
        {
            length +=7.0 * pow(0.98 ,n-1 );
        }
        else if(length >= s-x && length <= s+x)
        {
            double min = (s+x)- length ;
            if(min < 7.0 * pow(0.98 ,n-1 ))
            {
                printf("n");
                break;
            }
            else
            {
                printf("y");
                break;
            }
            
        }
        else if(length >= s+x)
        {
            printf("n");
                break;
        }
    }
    return 0;
}