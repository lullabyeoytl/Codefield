#include <stdio.h>
#include<string.h> 
#include <math.h>
int a[3000][3000]; int n;
int f (int t ,int r ,int c)
{
    if(t==2)
    a[r][c]=0;
    
    else
    {
        for(int i=r; i<=r+ t/2 -1 ;i++)
        {
            for(int j=c ; j<= c+ t/2 -1; j++)
            a[i][j]=0;
        }
        f(t/2 , r+t/2 ,c);
        f(t/2, r , c+t/2);
        f(t/2, r+t/2 , c+t/2);
    
    }
    return 0;
}   
    
int main (void)
    { 
        scanf("%d", &n);
       for(int k = 0 ; k< pow( 2,n); k++)
       {
        for (int l=0; l< pow (2,n) ; l++)
        a[k][l]=1;                
       }
       
      
       f( pow(2,n), 0 ,0);
       for(int i = 0 ; i< pow(2,n) ; i++)
       {
        for(int j = 0; j< pow(2,n) ; j++)
        {
            printf ("%d", a[i][j]);
            printf (" ");
        }
        printf("\n");
       }                     
       return 0;

    }
    //总结：函数递归精髓在于找到1一般形式与关键变量，首行声明2找到结束点写入函数定义3建立递推重新函数里引用函数
    /*int f(int x) {

if (x == 1) return 1; //如果x为1，则返回1!=1

return x * f(x - 1);

//否则递归调用函数计算(x-1)!，并且将其乘上x返回，从而得到x!的结果  此为要返回值的一个定义*/

    
