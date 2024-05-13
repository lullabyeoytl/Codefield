#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 51
int data[SIZE];
int main()
{
    memset(data ,0,sizeof(data));
    int index = 1;
    int n;
    int i,j,k;
    data[1] = 1;
    printf("Input n:");
    scanf("%d", &n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=index;j++)
        data[j] = data[j] *i;
    for(k=1;k<index;k++)
    {
        if(data[k]>=10)
        {
            data[k+1] += data[k]/10;
            data[k] %= 10;
        }
    }
    while(data[index] >= 10&& index <= SIZE-1)
    {
        data[index+1] = data[index]/10;
        data[index]%=10;
        index++;
    }
    if(index <= SIZE-1)
    {
        printf("%d!= ",i);
        for(j=index;j>0;j--)
        {
            printf("%d", data[j]);
        }
        printf("\n");
    }
    else
    {
        printf("Overflow!\n");
        exit(1);
    }
    }
    return 0;
}
