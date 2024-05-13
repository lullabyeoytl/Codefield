#include <stdio.h>
#include<string.h> 
#define maxn 1000
int main(void)
{
    int A[maxn][maxn];
    int n, m;
    scanf("%d%d", &n,&m);
    for(int a = 1; a<=n ; a++)
    {
        for(int b=1 ;b <= n; b++)
        A[a][b] = (a-1) * n + b;
    }                //矩阵初始化
    for (int c = 1 ; c<= m ; c++)
    {
        int x ,y , r, z;
        scanf("%d%d%d%d", &x, &y, &r ,&z );
        if (z==0)//顺时针
        {  
            int B[maxn][maxn];
            for( int d = x-r ; d<= x+r ; d++)
            {
                for( int e = y-r ; e <= y+r ; e++)
                {
                    
                    B[x+e-y][y+x-d] = A[d][e];//换序引入第三者
                }
            }
            for(int d = x-r ; d<= x+r ; d++)
            {
                for(int e =y-r ; e<= y+r; e++)
                A[d][e]=B[d][e];
            }

        }
        if (z==1)//逆时针
        {  
            int B[maxn][maxn];
            for( int d = x-r ; d<= x+r ; d++)
            {
                for( int e = y-r ; e <= y+r ; e++)
                {
                    
                    B[x+y-e][y-x+d] = A[d][e];//换序引入第三者
                }
            }
            for(int d = x-r ; d<= x+r ; d++)
            {
                for(int e =y-r ; e<= y+r; e++)
                A[d][e]=B[d][e];
            }

        }//稍改一下完全复制
        else
        continue;
    }
    for(int i = 1 ; i<=n ; i++)
       {
        for(int j = 1; j<= n ; j++)
        {
            printf ("%d", A[i][j]);
            printf (" ");
        }
        printf("\n");
       }                      //按输出格式输出
       return 0 ;                     


}