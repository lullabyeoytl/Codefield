#include <stdio.h>
#include<math.h>
#include<string.h>
int n, k;int tot = 0; int A[25]; 

void dps(int t , int o , int sum)
{
    if(t>=k
    )
    {
        int a = sqrt(sum); int b=0;
      for(int i = 2 ; i<=a ; i++)
        {
           if(sum%i==0)
            break;
            else
            b++;
        }
      if(b==a-1)
       tot++;
        return ;
    }
    if(t<=k-1)
    {
        for (int i =o+1 ; i<=t+n-k+1 ; i++)
            dps( t+1,i , sum+A[i]);
       
    }

    
}
int main (void)
{
    scanf("%d%d", &n,&k);
    for(int i=1 ; i<=n ; i++)
        scanf("%d" , &A[i]);
    dps(0 , 0 , 0);
    printf("%d", tot);
    getchar();
    getchar();getchar();
     return 0;
}