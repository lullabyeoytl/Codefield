#include <stdio.h>
#include <stdlib.h>
#define M 10
#define N 10
void transpose(int a[][N],int at[][M],int m,int n);
int main()
{
    int s[M][N],st[N][M],m,n;
    printf("Input m,n:");
    scanf("%d,%d",&m,&n);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&s[i][j]);
            st[j][i]=s[i][j];
        }
    }
    transpose(s,st,m,n);
    for(int i =0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d ",st[i][j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
void transpose(int a[][N],int at[][M],int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            at[j][i]=a[i][j];
        }
    }
}
