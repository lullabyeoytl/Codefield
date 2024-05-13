#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    if(n>=15)
    {
        if(n%5==0)
        {
            printf("%d",n/5);
        }
        else if(n%5==1)
        {
            printf("%d",(n-6)/5+2);
        }
        else if(n%5==2)
        {
            printf("%d",(n-12)/5+4);
        }
        else if(n%5==3)
        {
            printf("%d",n/5+1);
        }
        else if(n%5==4)
        {
            printf("%d",(n-9)/5+3);
        }
    }
    else
    {
        if(n==1||n==2||n==4||n==7)
        {
            printf("-1");
        }
        if(n==3)printf("1");
        if(n==5)printf("1");
        if(n==6)printf("2");
        if(n==8)printf("2");
        if(n==9)printf("3");
        if(n==10)printf("2");
        if(n==11)printf("3");
        if(n==12)printf("4");
        if(n==13)printf("3");
        if(n==14)printf("4");
    }
    return 0;
}