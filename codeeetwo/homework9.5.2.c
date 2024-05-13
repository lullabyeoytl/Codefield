#include <stdio.h>
int DayTab0[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int DayTab1[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
void MonthDay(int year, int yearDay, int *pMonth,int *pDay)
{
    if(((year%4)==0 &&(year%100 != 0) ) || (year%400==0))
    {
        int s = yearDay;int i = 1;
        while(s - DayTab1[i] >0)
        {
            s -= DayTab1[i];
            i+=1; 
        }
        *pMonth = i;
        *pDay = s;
        
    }
    else
    {
        int s = yearDay;int i = 1;
        while(s - DayTab0[i] >0)
        {
            s-=DayTab0[i];
            i+=1; 
        }
        *pMonth = i;
        *pDay = s;

    }
}
int main()
{
    int year,month,day,yearDay;
    printf("Please enter year,yearDay ");
    scanf("%d%d",&year,&yearDay);
    MonthDay(year,yearDay,&month,&day);
    printf("month = %d,day = %d\n",month ,day);
    return 0;
}