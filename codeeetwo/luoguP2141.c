#include <stdio.h>
#include<stdlib.h>
#include <string.h>
int a[105];int b[105];
int main(void)
{
    memset(b, 0 , sizeof b);
    int n; int res = 0;
    scanf("%d" , &n);
    for(int i = 1; i<= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i<= n-1; i++)
    {
        for(int j = i+1 ; j<=n; j++)
        {
            int t = abs(a[j]+a[i]);
            for(int k = 1; k<= n ; k++)
            {
                if(t==a[k])
                b[k]++;
            }
        }
    }
    for(int i = 1; i<=n ; i++)
    {
        if(b[i]>0)
        res++;
    }
    printf("%d", res);
    return 0;

}

