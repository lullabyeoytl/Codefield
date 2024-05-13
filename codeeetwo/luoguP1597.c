#include <stdio.h>
#include <math.h>
int prime[20000]; int n;
int check(int t)
{ 
    int q1 = 0;
       for(int j= 2; j<= sqrt(t); j++)
       {
        if(t%j == 0)
        q1++;
       }
       if(q1==0)
       return t;
       else
       return 0;
  
}
int main(void)
{ 
    scanf("%d", &n);int wa = n-4;
    if(check(n-4) != 0)
   printf("2 2 %d" , wa);
   else
   {
     prime[1] = 2; prime [2] = 3;
     for (int i=3;i<n;i++)//第二种情况
	if((i%2)!=0&&check(i))//优化
	for (int j=i;j<n;j++)
		if((j%2)!=0&&check(j))//优化
		if(check(n-i-j)) {
		printf("%d %d %d" , i, j, n-i-j);
        goto END;
        //不用循环第三个数，优化。
        }
   }
  END:  return 0;

   
}