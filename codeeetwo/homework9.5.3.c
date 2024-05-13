#include <stdio.h>
#include <stdlib.h>
int DayTab0[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int DayTab1[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int DayofYear(int year,int month,int day)
{
    int i,leap;
    leap = ((year%4)==0 &&(year%100 != 0) ) || (year%400==0);
    for(i=1;i<month;i++)
    {
        if(leap)
        day+=DayTab1[i];
        else
        day+=DayTab0[i];
    }
    return day;
}

void MonthDay (int year,int yearDay, int * pMonth, int * pDay)
{
    if(((year%4)==0 &&(year%100 != 0) ) || (year%400==0))
    {
        int s = yearDay;int i = 1;
        while(s - DayTab1[i] >0)
        {
            s -= DayTab1[i];
            i+=1; 
        }
        * pMonth = i;
        * pDay = s;
        
    }
    else
    {
        int s = yearDay;int i = 1;
        while(s - DayTab0[i] >0)
        {
            s-=DayTab0[i];
            i+=1; 
        }
        * pMonth = i;
        * pDay = s;
    }
}

void Menu (void)
{
    printf("1.year/month/day -> yearDay\n");
    printf("2.yearDay -> year/month/day\n");
    printf("3.Exit\n");
    printf("Please enter your choice");
}



int main()
{
    int year,month,day,yearDay;
    char c;
    Menu();
    c = getchar();
    switch(c)
    {
        case '1' :printf("Please enter year , month, day:");
                scanf("%d%d%d", &year,&month,&day);
                yearDay = DayofYear(year, month,day);
                printf("yearDay = %d\n",yearDay);
                break;
        case '2' :printf("Please enter year,yearDay:");
                scanf("%d%d", &year,&yearDay);
                MonthDay(year,yearDay,&month,&day);
                printf("month = %d,day=%d\n", month,day);
                break;
        case '3' :exit(0);
        default: printf("Wrong Input");
              
    }
    return 0;
}
