#include <stdio.h>
int main()
{
    int iNum;
    scanf("%d", &iNum);
    //输入数总数

    int iMin = 10000000; int iMax = -1;
    for(int i = 1; i<= iNum; i++)
    {
        int iTemp;
        scanf("%d", &iTemp);
        if(iTemp <= iMin)
        {
            iMin = iTemp;
        }
        if(iTemp >= iMax)
        {
            iMax = iTemp;
        }
    }
    //输入每个数并找出最大最小
    
    int iRes = iMax - iMin;
    printf("%d", iRes);
    //输出结果
    return 0;
}