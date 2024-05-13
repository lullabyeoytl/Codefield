#include <stdio.h>
#include <string.h>
#define weekday 7
int main()
{
    int i,pos;
    int find = 0;
    char x[10];
    char day[][10]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    printf("enter ");
    scanf("%s",x);
    for(i=0;i<weekday&&!find;i++)
    {
        if(strcmp(x,day[i])==0)
        {
            pos = i;
            find = 1;
        }
    }
    if(find)
    {
        printf("%s is %d\n",x,pos);
    }
    else 
    printf("Not Found!\n");
    return 0;
}