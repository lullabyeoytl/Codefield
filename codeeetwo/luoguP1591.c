#include <stdio.h>
#include<string.h>
int A[10];int SUM[3000] ; int DSUM[3000];int ESUM[3000]; int output [11];//DSUM代替sum来乘法；Esum只用于储存结果
int main (void)
{
    int t;
    memset(SUM,0 ,sizeof(int)*3000 );
    memset(A,0 ,sizeof(int)*10 );
    memset(DSUM,0 ,sizeof(int)*3000 );
    memset(ESUM,0 ,sizeof(int)*3000 );
    SUM[0]=1;
    scanf("%d" , &t);
    getchar();
    for(int b = 1 ; b <= t ; b++)
    {
         int n , a;    //n为要结成的，为目标数码；
         scanf("%d%d" , &n , &a); 
        
         for(int i = 2; i<= n ; i++)//将要乘的数变成数组,循环中进行高精度乘法
         { 
             int j=0;//j用来记位数,应放这个for里面来每次清零
             for(int c = 0;c<=2900; c++)
                DSUM[c]=SUM[c];//先拷贝出一个SUM
                int k=i ;
            while( k/10 !=0)
            {
                  A[j]=k-(k/10)*10;
                  k/=10;
                  j++;
            }
            A[j]=k; 
        
            for(int c = 0;c<=2900; c++)
            {
                for(int d=0; d<= c ; d++)
                {
                    if(c-d>7)
                    break;                     //调试时发现，注意要小心数组编码不够而导致的溢出
                    else
                    ESUM[c] += DSUM[d]*A[c-d];         
                }
                ESUM[c+1]+=ESUM[c]/10;
                    ESUM[c]%=10;
            }                               //高精度乘法结束，Esum为结果
            for(int f =0 ; f<=2900; f++)
            SUM[f]=ESUM[f];           //sum=n!（有bug 5!显示240，7！显示13440）
        }

         int g; int s=0;//s用于记数码次数 
        for(g=2999; g>=0; g--)
        {
            if(SUM[g] == 0) 
            continue;
            if(SUM[g]!= 0)
            break;
        }                     //找到第一个非0的sum[g]  
        for(int h=g; h>=0; h--)
         {
            if(SUM[h]==a)
            s++;
            else
            continue;
         }

        output[b]=s;
    }
    for(int i = 1 ; i<= t; i++)
        
    printf("%d\n" , output[i]);
    return 0;


}