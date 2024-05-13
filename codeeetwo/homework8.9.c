#include <stdio.h>
#define N 10
void InputMatrix (int a[N][N], int n);
int AddDiag(int a[N][N], int n);
int main()
{
    int a[N][N], n, sum;
    printf("Input n :");
    scanf("%d", &n);
    InputMatrix(a,n);
    sum = AddDiag(a,n);
    printf("sum = %d\n", sum);
    return 0;
}

void InputMatrix (int a[N][N], int n)
{
    int i, j;
    printf("Input %d * %d matrix: \n", n, n);
    for(i= 0; i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

int AddDiag(int a[N][N], int n)
{
    int i,j,sum = 0;
    for(i = 0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j||i+j==n-1)
            sum += a[i][j];
        }
    }
    return sum;
}





