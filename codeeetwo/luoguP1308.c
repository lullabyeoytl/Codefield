//strstr(char *str1, const char *str2)：
//若 str2 是 str1 的子串，则返回 str2 在 str1 的首次出现的地址；如果 str2 不是 str1 的子串，则返回 NULL。
/*
#include <stdio.h>
#include <string.h>
char a[15] ; char b[1000020]; int c[1000020]; int ans = -1;

void check(int w , int t , int shouwei)//w表示检测到了a[w], t表a位数 
{
    if(w == 0)
    {
        for(int j = 0; j<= 1000001; j++ )
        {
            if(b[j] == a[0])
            {
                if( j == 0 || b[j-1] ==' ')
                check(1 , t , j);
            }
        }
    }
    if( w >= 1 && w <= t-2)
    {
        if(b[shouwei+1] == a[shouwei+1])
        check(w+1 , t , shouwei+1);
    }
    if(w == t-1)
    {
        if(b[shouwei+1] == a[shouwei+1])
          { 
            ans ++;
            c[shouwei + 2 - t] = 1 ;
          }
    }

}

int main(void)
{
    memset(c , 0 ,sizeof(c));
    gets(a); gets(b);
   int i = 0;
   while(a[i] != ' ')
   i++; //a[i-1]为末尾
   for(int j = 0 ; j <= i; j++)
   {
    if(a[j] >= 'a' && a[j] <= 'z')
    a[j] -= 32; //统一转成大写
   }
   for(int k = 0 ; k <= 1000001; k++)
   {
    if(b[k] >= 'a' && b[k] <= 'z')
    b[k] -= 32; //统一转成大写
   }  
   check(0 , i ,0);
   if(ans != -1)
   {
     ans++;
     int q = 0;
     for( ;q<=100001; q++)
     {
        if(c[q] == 1 )
        break;
     }
     printf("%d %d" , ans , q);
   }
   else
   printf("-1");
   return 0;
   

}
*/

