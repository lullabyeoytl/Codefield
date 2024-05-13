#include <stdio.h>
int m;
int fib(int t)
{
    if(t==0)
    return 0;
    if(t==1)
    return 1;
    else
    return fib(t-1)%m+fib(t-2)%m;
}
int main(void)
{
    scanf("%d", &m);
    int i =0;
    while(fib(i)!=m-1||fib(i+1)!=1)
    i++;
    printf("%d", i+3);
    return 0;
}

