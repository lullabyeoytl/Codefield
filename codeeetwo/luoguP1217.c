#include <stdio.h>
#include <math.h>
int temp[10];
int main(void)
{
    int a,b;
    scanf("%d%d", &a ,&b);
    for(int i = a; i<=b ; i+=2 )
    {
        int s1=0;
        for(int j = 2 ; j<= sqrt(i); j++ )
        {
            if(i%j == 0)
            s1 ++;
        }
        if(s1 == 0)
        {
            int s2 = i;int k =1;
            while(s2 / 10 > 0)
            {
                temp[k] = s2 %10;
                s2 /= 10;
                k++;
            }
            temp[k] = s2; 
            int i1= 0;
            for(int p = 1 ; p<= k ; p++)
            i1 += temp[p] * pow(10, k-p);
            if( i1 == i)
            printf("%d\n" , i1);
            
        }
    }
    return 0;
}