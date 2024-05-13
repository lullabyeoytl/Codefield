// code here
#include <stdio.h>
#include <string.h>
#define T 32767
int iMemory[1000];//记忆化数组

//PellSequence,计算数列第k项
int PellSequence(int k)
{
    if(k==1)
    {
        return 1;
    }
    else if(k==2)
    {
        return 2;
    }
    else
    {
       if(iMemory[k]!=0)//不等于零表示调用过了
        {
        return iMemory[k];
        }
       else
      {
          return iMemory[k]=((PellSequence(k-1)*2+PellSequence(k-2)))%T;
      }
    }

}

int main()
{
    int iNum;
    scanf("%d",&iNum);
    //输入组数
    memset(iMemory,0,sizeof(iMemory));
    //记忆化数组要清零表示开始均为用过
    for(int i = 1;i<=iNum;i++)
    {
        int iTemp;
        scanf("%d",&iTemp);
        printf("%d\n",PellSequence(iTemp));
    }
    return 0;
}