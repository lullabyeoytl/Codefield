#include<stdio.h>
#include <stdlib.h>
#define N 10
int s[N+1][N+1];
/*
void Swap(int * x, int * y)
{
    int temp;
    temp = *x;
    *x=*y;
    *y=temp;
}

void Transpose(int a[][N], int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(int j =i;j<n;j++)
        {
            Swap(&a[i][j],&a[j][i]);
        }
    }
}
*/
int main()
{
    int n;
    printf("Input n: ");
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&s[i][j]);
        }
    }
    //Transpose(s,n);
    printf("The transposed matriix is: \n");
    for(int i = 0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",s[j][i]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
    
}