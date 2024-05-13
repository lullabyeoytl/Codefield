#include <stdio.h>
#include <math.h>
#include <string.h>
//PrimeCheck：判断t是否为函数
// 返回值：是返回1，否返回0
int PrimeCheck(int t)
{
   if(t==1)
   {
    return 0;
   }
    if(t==2 || t==3)
    {
    return 1;
    }
    //1,2，3要特判

     int cnt = 0;
    for(int i = 2; i<=sqrt(t)+1; i++)
    {
        if( t % i == 0)
        {
            cnt ++;
        }
        else
        continue;
    }
    if(cnt == 0)
    {
    return 1;
    }
    else 
    {
    return 0;
    }
}


int iRes[15];
int main()
{
    memset(iRes, 0, sizeof(iRes));
    int iGroupNum;
    scanf("%d", &iGroupNum);
    //输入判断组数
    for(int i = 1; i<= iGroupNum; i++)
    {
        int iNumi;
        scanf("%d", &iNumi);//输入i组数个数
        for(int j =1; j<= iNumi; j++)
        {
            int iNumij; 
            scanf("%d", &iNumij);//输入i组第j个数
            if(PrimeCheck(iNumij)==1)
            {
                iRes[i] += iNumij;//计算i组素数和
            }
        }
    }
    //下输出
    for(int i =1; i<= iGroupNum; i++)
    {
        printf("%d\n", iRes[i]);
    }
    return 0;
}