#include <stdio.h>
#include <string.h>
int A[40][40];int n;
void hf(int t ,int x, int y)
{
    if(t==1)
    {
        A[1][(n+1)/2] = 1;
        hf(2,(n+3)/2 , n);
    }
    if(t>=2&&t<=n*n)
    {
        if(x == 1 && y != n)
       {
        A[n][y+1] = t+1;
        hf(t+1, n , y+1);
       } 
       if(y == n && x != 1)
       {
        A[x-1][1] = t+1;
        hf(t+1 , x-1 , 1);
       }
       if(x== 1 && y == n)
       {
        A[x+1][y] = t+1;
        hf(t+1 , x+1 , y);
       }
       if(x!= 1 && y != n)
       {
        if(A[x-1][y+1] != 0)
        {
            A[x-1][y+1] = t+1;
            hf( t+1 , x-1 , y+1);
        }
        else
        {
            A[x+1][y] = t+1 ; 
            hf(t+1, x+1 , y) ;
        }
       }
    }
    if(t >= n*n +1)
    return ; 

}
int main (void)
{
  memset(A , 0, sizeof A);
  scanf("%d" , &n);
  hf(1,(n+1)/2 , 1);
  for(int i = 1 ; i<=n ;i++)
  {
    for(int j=1; j<=n ; j++)
    {
        printf("%d", A[i][j]);
        printf(" ");
    }
    printf("\n");
    printf("\n");
  }
  getchar();
  getchar();
  return 0;
}