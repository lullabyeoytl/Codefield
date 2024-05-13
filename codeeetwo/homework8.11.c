#include <stdio.h>
#include <string.h>
#define N 25
void Caculateyh (int a[][N], int n);
void Printyh(int a[][N], int n);
int a[N][N];
int main()
{
     int n;
     memset (a,0,sizeof(a));
     printf("Input n(n<20):");
     scanf("%d", &n);
     Caculateyh(a,n);
     Printyh(a,n);
     return 0;

}

void Caculateyh (int a[][N], int n)
{
    int i , j;
    for(i=0;i<n;i++)
    {
        a[i][0]= 1;
        a[i][i] = 1;
    }
    for(i=2;i<n;i++)
    {
        for(j=1;j<=i-1;j++)
        {
            a[i][j] = a[i-1][j-1] + a[i-1][j];
        }
    }
    return ;
}

void Printyh(int a[][N], int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
    return ;
}