/*
#include <stdio.h>
#include <string.h>
int a[105];int b[105];
int main(void)
{
    memset(b, 0, sizeof b);
    int n ;
    scanf("%d", &n);
    for(int i = 1; i<=n;i++ )
    {
        scanf("%d" , &a[i]);
    }
    for(int i = n; i>=1; i--)
    {
        for(int j = i-1 ; j>= 1; j--)
        {
            if(a[j] < a[i])
            b[i]++;
        }
    }
    for(int i = 1; i<=n;i++ )
    {
        printf("%d" , b[i]);
        printf(" ");
    }
    return 0;
}
*/
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
    int ma = -1;
    for(int i=1 ; i<= n; i++ )
    {
        for(int j = i+1 ; j<= n ; j++)
        {
            if(a[j] > a[j-1])
            b[i]++;
            else
            break;
        }
        if(b[i] > ma)
        ma = b[i];
    
    }
        
    ma += 1;
    printf("%d" , ma);
    return 0;
}