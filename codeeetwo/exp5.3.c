#include<stdio.h>
#include<string.h>
int iUsed[10];//ai表示第i个数已经用过了
int main()
{
    for(int i=192;i<=327;i++)//第一个数最小192，最大327。其实不知道的情况下简单来说是从123-329的但是算出来是最值就稍微改了下下
    {
        memset(iUsed,0,sizeof(iUsed));
        int iSumused=0;//清零
        iUsed[i%10]=iUsed[i/10%10]=iUsed[i/100]=iUsed[i*2%10]=iUsed[i*2/10%10]=iUsed[i*2/100]=iUsed[i*3%10]=iUsed[i*3/10%10]=iUsed[i*3/100]=1;//统计数字
        for(int j=1;j<=9;j++) 
        {
            iSumused+=iUsed[j];//iSumused表示1-9这些数字是否全部齐了
        }
        if(iSumused==9) 
        {
            printf("%d %d %d\n",i,i*2,i*3);//如果齐了就输出
        }
    }
    return 0;
}