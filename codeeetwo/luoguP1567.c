#include <stdio.h>
#include <string.h>
int a[1000005]; int b[1000005];
int main(void)
{
    memset(b, 0 , sizeof b);
    int n;
    scanf("%d", &n);
    for(int i = 1; i<= n ; i++)
    {
        scanf("%d", &a[i]);
    }
    
    for(int i=1 ; i<= n-1; i++ )
    {
        if(a[i+1]>a[i])
        {
            b[i+1] = b[i]+1;
        }
    
    }
    int ma = b[1];
    for(int i=1 ; i<= n-1; i++ )
    {
        if(b[i+1]>ma)
        ma = b[i+1];
    }
        
    ma += 1;
    printf("%d" , ma);
    return 0;
}