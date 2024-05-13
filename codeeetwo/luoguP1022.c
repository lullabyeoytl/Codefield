#include <stdio.h>
#include <string.h>
#include <math.h>
char a[1000]; double x1 = 0; double x2 = 0;char alpha;//x1字母系数x2数
int main(void)
{
    gets(a);int de;
    a[strlen(a)] = ' ';
    for(de = 0; de<=strlen(a) -1;de++)
    {
        if(a[de] == '=')
        break;
    }//a[de] = '='
    for(int i = 0; i<=de-1; i++)
    {
        if(a[i] >= 'a' && a[i] <='z')
        {
            alpha = a[i];
            int tempsum = 0;int w1=0;
            if(a[i-1] == '+'|| i==0)
            x1+=1;
            else if(a[i-1] == '-')
            x1-=1;
            else
            {
                do
                {
                    tempsum += (a[i-1-w1]-48)*pow(10,w1);
                    w1+=1;
                } while (a[i-1-w1] >= '0' && a[i-1-w1] <= '9'&& i-1-w1 >=0);
                if(i-1-w1 == -1 || a[i-1-w1] == '+')
                {
                    x1 += tempsum;
                }
                else if(a[i-1-w1] == '-')
                {
                    x1 -= tempsum;
                }
                
            }
        }
        else
        continue;
    }
    //处理完了等号左边字母系数；
    for(int i = de+1; i<=strlen(a)-1; i++)
    {
        if(a[i] >= 'a' && a[i] <='z')
        {
            int tempsum = 0;int w2=0;
            if(a[i-1] == '+'|| i==de+1)
            x1-=1;
            else if(a[i-1] == '-')
            x1+=1;
            else
            {
                do
                {
                    tempsum += (a[i-1-w2]-48)*pow(10,w2);
                    w2+=1;
                } while (a[i-1-w2] >= '0' && a[i-1-w2] <= '9');
                if(a[i-1-w2] == '+'||a[i-1-w2] == '=')
                {
                    x1 -= tempsum;
                }
                if(a[i-1-w2] == '-')
                {
                    x1 += tempsum;
                }
                
            }
        }
        else
        continue;
    }//处理完等号右边字母系数
   for(int i = 0; i<=de-1; i++)
   {
      if((a[i+1] == '+' || a[i+1] == '-'||a[i+1] == '=')&&( a[i] >= '0' && a[i] <= '9'))
      {
        int tempsum = 0;int w=0;
             do
                {
                    tempsum += (a[i-w]-48)*pow(10,w);
                    w+=1;
                } while (a[i-w] >= '0' && a[i-w] <= '9'&& i-w >=0);
                if(i-w == -1 || a[i-w] == '+')
                {
                    x2 -= tempsum;
                }
                if(a[i-w] == '-')
                {
                    x2 += tempsum;
                }
        }
        else 
        continue;
   }
   for(int i = de+1; i<=strlen(a)-1; i++)
   {
      if((a[i+1] == '+' || a[i+1] == '-'||a[i+1] ==' ' )&&( a[i] >= '0' && a[i] <= '9'))
      {
        int tempsum = 0;int w=0;
             do
                {
                    tempsum += (a[i-w]-48)*pow(10,w);
                    w+=1;
                } while (a[i-w] >= '0' && a[i-w] <= '9');
                if(i-w == de || a[i-w] == '+')
                {
                    x2 += tempsum;
                }
                if(a[i-w] == '-')
                {
                    x2 -= tempsum;
                }
        }
        else 
        continue;
   }
double res = x2/x1;
if(res==-0.0) res=0;
printf("%c=%.3lf" ,alpha, res);
return 0;

}