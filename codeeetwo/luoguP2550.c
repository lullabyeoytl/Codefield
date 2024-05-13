#include <stdio.h>
#include<string.h> 
int main (void)
{
    int n,A[10],B[1005][10],C[10];
    memset(C, 0, sizeof(int) * 10);
    scanf("%d",&n);
    for(int i = 1; i<=7;i++)
    {
        scanf("%d",&A[i]);//标准彩票输入
    }
    for(int j = 1; j<=n;j++)//每张的开始
    {
        int num=0;
        for(int k=1; k<=7; k++)//每张彩票数字开始
       {
         scanf("%d",&B[j][k]);
         
       for(int l=1;l<=7;l++)
        {
        
          if(B[j][k]==A[l])
          num+=1;
        }
       
       }      
          int t=7-num;             //每张输入完同时也比对完
       C[t]+=1;             //总的才加一

    }
    for(int m=0;m<=6;m++)//输出
   {
     printf("%d",C[m]);
    printf(" ");
   }
  getchar();
    getchar();
    getchar();
    getchar();
    getchar();
    getchar();
    getchar();
    getchar();
    return 0;
}             
        

    