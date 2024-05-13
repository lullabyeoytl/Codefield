#include <stdio.h>
#include <stdlib.h>
#define M 10
#define N 10
void inputmatrix(int * p,int m, int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&p[i*n+j]);
        }
    }
}

int findmax(int * p,int m, int n, int *prow, int *pcol)
{
    int i,j,max=p[0];
    *prow = 0;
    *pcol = 0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(p[i*n+j]>max)
            {
                max = p[i*n+j];
                *prow = i;
                *pcol = j;
            }
        }
    }
    return max;
}

int main()
{
    int * a,m,n,row,col,max;
    scanf("%d%d",&m,&n);
    a = (int *)calloc(m*n, sizeof(int));
    if(a==NULL)
    {
        exit(0);
    }
    
    inputmatrix(a,m,n);
    max = findmax(a,m,n,&row,&col);
    printf("max=%d,row = %d,col=%d\n",max,row,col);
    free(a);//!不要忘了！
    system("pause");
    return 0;
}