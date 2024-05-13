#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define iConstn1 105
int iNum[iConstn1];
//iSwap交换函数，输入两变量地址，交换a,b地址
void iSwap(int * a, int * b)
{
    int  iTemp;
    iTemp = *a;
    *a = *b;
    *b = iTemp;
}
//iSort 排序函数，a[]为排序的数组，n为数组大小
void iSort(int a[],int n)
{
    for(int i=0;i<=n-2;i++)
    {
        for(int j=i+1;j<=n-1;j++)
        {
            if(a[i]>=a[j])
            {
                iSwap(&a[i],&a[j]);
            }
        }
    }
}

int main()
{
    int iNumScan;
    scanf("%d",&iNumScan);
    for(int i=0;i<=iNumScan-1;i++)
    {
        scanf("%d",&iNum[i]);
    }
    //输入
    iSort(iNum,iNumScan);//先排序
    int iNumPrint=1;
    for(int j=1;j<=iNumScan-1;j++)
    {
        if(iNum[j]!=iNum[j-1])
        {
            iNumPrint+=1;
        }
    }
    //统计多少种数
    printf("%d\n",iNumPrint);
    printf("%d ",iNum[0]);
    for(int j=1;j<=iNumScan-1;j++)
    {
        if(iNum[j]!=iNum[j-1])
        {
            printf("%d ",iNum[j]);
        }
    }//输出
   //system("pause");
    return 0;
}