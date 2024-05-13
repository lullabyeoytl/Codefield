#include <stdio.h>
#define N 10
void swap(int * x,int * y );
void transpose (int *a,int n);
int main()
{
    int s[N][N],n;
    printf("Input n: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&s[i][j]);
        }
    }
    transpose(*s,n);
     for(int i = 0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",s[j][i]);
        }
        printf("\n");
    }
    return 0;
}
void Swap(int *x,int *y)
{
    int temp;
    temp = *x;
    * x = * y;
    *y = temp;
}
void Transpose(int *a,int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            Swap(&a[i*n+j],&a[j*n+i]) ;
        }
    }
}