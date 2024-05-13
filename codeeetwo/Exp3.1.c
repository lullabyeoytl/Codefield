#include <stdio.h>
#include <math.h>
int main()
{
    int iRate,iMoney,iYear;
    double dRate2;
    scanf("%d %d %d", &iRate, &iMoney, &iYear);
    //输入年利率iRate,现有总金额iMoney,年份iYear
    dRate2 = (double)iRate / 100.0 ;//利率百分数转为转为小数
    int iSum = pow(1+dRate2, iYear) * (double)iMoney;
    //计算金额公式
    printf("%d", iSum);//输出
    return 0;
}

