#include <stdio.h>
int main (void)
{
    int n,m; float sum;
    scanf("&d&d" ,&n,&m);//不要忘记这两个逗号
    for(int j = n ;j<=m ; j++)
    {
        sum+=(float)1/j/j;
    }
    printf("%.5lf\n" , sum);
    getchar();
    getchar();
    getchar();
    getchar();
    return 0;

}