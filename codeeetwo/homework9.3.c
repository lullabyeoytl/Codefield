#include <stdio.h>
int swap(int *x,int *y )
{
    int temp;
    temp = *x;
    *x = *y ;
    *y = temp;
    return 0;
}
int a[10];int b[10];
int main()
{
    int n;
    printf("size of a,b =  ");
    scanf("%d", &n);
    for(int i = 1; i<=n;i++)
    {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i<=n;i++)
    {
        scanf("%d", &b[i]);
    }
    for(int i = 1; i<=n;i++)
    {
        swap(a+i,b+i);
    }
    for(int i = 1; i<=n;i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    for(int i = 1; i<=n;i++)
    {
        printf("%d ", b[i]);
    }
    return 0;
}