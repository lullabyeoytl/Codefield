#include <stdio.h>

int main(void)
{
    int c[9];
    float A,B,C;int res =0;
    scanf("%f%f%f", &A,&B,&C);
    for(int i = 123 ; i<= 798; i++)
   {
      if((float) (i/A) != (float)i/A ) 
      {
     int i2 = (float)(i * B) / A  +1;
     int i3 = (float)(i * C) /A  +1;
      c[0] = i%10;
     c[1] = i / 100;
     c[2] = (i/10) % 10;
     c[3] = i2%10;
     c[4] = i2 / 100;
     c[5] = (i2/10) % 10;
     c[6] = i3%10;
     c[7] = i3 / 100;
     c[8] = (i3/10) % 10;
     if(c[0]*c[1]*c[2]*c[3]*c[4]*c[5]*c[6]*c[7]*c[8] == 362880&&c[0]+c[1]+c[2]+c[3]+c[4]+c[5]+c[6]+c[7]+c[8] == 45)
     {
     printf("%d %d %d\n", i,i2,i3);
     res++;
     }
      }
      else
      {
    int i2 = (i * B) / A ;
     int i3 = (i * C) /A ;
      
     c[0] = i%10;
     c[1] = i / 100;
     c[2] = (i/10) % 10;
     c[3] = i2%10;
     c[4] = i2 / 100;
     c[5] = (i2/10) % 10;
     c[6] = i3%10;
     c[7] = i3 / 100;
     c[8] = (i3/10) % 10;
     if(c[0]*c[1]*c[2]*c[3]*c[4]*c[5]*c[6]*c[7]*c[8] == 362880&&c[0]+c[1]+c[2]+c[3]+c[4]+c[5]+c[6]+c[7]+c[8] == 45)
     {
     printf("%d %d %d\n", i,i2,i3);
     res++;
     }
   } 
   }
   if(res == 0)
   printf("No!!!");
   return 0;
  

}