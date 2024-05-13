#include <stdio.h>
#define N 25
void Insert(int a[], int n, int x);
int a[N];
int main()
{
    int x,i,n;
    printf("Input array size:");
    scanf("%d", &n);
    printf("Input array:");
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Input x:");
    scanf("%d", &x);
    Insert(a,n,x);
    printf("After insert %d:\n",x);
    for(i=0;i<n+1;i++)
    {
        printf("%4d", a[i]);
    }
    printf("\n");
    return 0;
}

void Insert(int a[], int n, int x)
{
    int i= 0; int pos;
    while(i<n && x>a[i])
    {
        i++;
    }
    pos = i;
    for (i=n-1;i>=pos;i--)
    {
        a[i+1]=a[i];
    }
    a[pos]=x;
    return ;
}