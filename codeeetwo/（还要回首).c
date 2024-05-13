/*#include <stdio.h>
#include <string.h>
int main(void)
{
    int sum[10000]; int n;
    memset(sum,0,sizeof(int)*10000);
    sum [1]=2;
    scanf("%d" , &n);
    int a =2;
    while((a*a+a - 2)/2 < n )
    a++;
    int b = (a*a-a-2)/2; int c = n-b;//c为余项
    if( n == (a*a+a - 2) / 2 && n != 3 &&n != 4)   //此时a已然为
    {
        for(int d = 3 ; d<=a ; d++)
        {
            int A[10000]; int f=1;   
             memset(A,0,sizeof(int)*10000);      //数组储存d
            while(d/10 != 0)
            {
                int e = d-(d/10)*10;
                A[f]=e;
                f++;d /= 10;            //f循环后等于位数
            }
            A[f]=d;    int  B[10000];                //末尾循环没记到数组里,A[1]为末尾
          for(int g =1 ; g<=10000; g++)
          {
            
            memset(B ,0 , sizeof(int)*10000);
            for(int h=1;h<=g; h++)
            B[g]+=sum[h]*A[1+g-h];
            int i =B[g];            //i用于暂时储存Bg
             if(i/10 != 0)
           { 
            B[g]=i%10;
            B[g+1]+= (B[g]-i%10)/10;
           }
          }
          for(int g =1; g<=10000; g++)
           sum[g]=B[g];                            //完成高精度sum*d
        }
        //开始输出
        for(int d = 3 ; d<=a ; d++)
        printf("2%d" , d);
        printf("\n");
        int i;
        for(i=10000;i>=1; i--)
        {
            if(sum[i] = 0) 
            continue;
            if(sum[i]!= 0)
            break;
        }                     //找到第一个非0的sum[i]            
        for(int q = i ; q>=1 ;  q--)
        printf("%d", sum[q]);
    }
    if( n != (a*a+a - 2) / 2 && n != 3 && n !=4 ) 
    {
        int j =a-1+c;
         for(int d = 2 ; d<=a-1 ; d++)
        {
            int A[10000]; int f=1;   
             memset(A,0,sizeof(int)*10000);      //数组储存d
            while(d/10 != 0)
            {
                int e = d-(d/10)*10;
                A[f]=e;
                f++;d /= 10;            //f循环后等于位数
            }
            A[f]=d;    int  B[10000];                //末尾循环没记到数组里,A[1]为末尾
          for(int g =1 ; g<=10000; g++)
          {
            
            memset(B ,0 , sizeof(int)*10000);
            for(int h=1;h<=g; h++)
            B[g]+=sum[h]*A[g+1-h];
            int i =B[g];            //i用于暂时储存Bg
             if(i/10 != 0)
           {
             B[g]=i%10;
            B[g+1]+= (B[g]-i%10)/10;
           }
          }
          for(int g =1; g<=10000; g++)
           sum[g]=B[g];                            //完成高精度sum*d
        }
        int A[10000]; int f=1;                     //单独处理j余项乘以sum
             memset(A,0,sizeof(int)*10000);      //数组储存d
            while(j/10 != 0)
            {
                int e = j-(j/10)*10;
                A[f]=e;
                f++;j /= 10;            //f循环后等于位数
            }
            A[f]=j;    int  B[10000];                //末尾循环没记到数组里,A[1]为末尾
          for(int g =1 ; g<=10000; g++)
          {
            
            memset(B ,0 , sizeof(int)*10000);
            for(int h=1;h<=g; h++)
            B[g]+=sum[h]*A[g+1-h];
            int i =B[g];            //i用于暂时储存Bg
             if(i/10 != 0)
           { 
            B[g]=i%10;
            B[g+1]+= (B[g]-i%10)/10;
           }
          }
          for(int g =1; g<=10000; g++)
           sum[g]=B[g];  
           for(int d = 2 ; d<=a ; d++) //开始输出
        { 
            printf("%d" , d);
            printf(" ");
        }
        printf("\n\n");
        int i;
        for(i=10000;i>=1; i--)
        {
            if(sum[i] = 0) 
            continue;
            if(sum[i]!= 0)
            break;
        }                     //找到第一个非0的sum[i]            
        for(int q = i ; q>=1 ;  q--)
        printf("%d", sum[q]);                 
        

    }
    if(n == 3)
    {
        printf("3\n");
        printf("3\n");
    }
    if(n == 4)
    {
        printf("4\n");
        printf("4\n");
    }
    getchar();
    getchar();
    return 0;
 }     
*/
//目前还解不了……未来再看！
            


                
            
        
    
  
