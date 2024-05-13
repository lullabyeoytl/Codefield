#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXNNUM 15

//user类型：存放用户的id(iUserID整型变量)，姓名（cUserName字符数组），收入（iIncome整型），支出（iExpense整型）
typedef struct user
{
    int iUserID;
    char cUserName[MAXNNUM];
    int iIncome;
    int iExpenses;
}user;
    int iChoiceScan;
    int iPeoplenum;
    double dAverin; double dAverout;

//Promptword():输出提示信息，无返回值：
void Promptword();
//Average:输入结构体user数组，人数，变量dAverin(代表平均收入)的地址，变量dAverout(代表平均支出)的地址
//计算收入支出平均值赋值给dAverin,dAverout,无返回值
void Average(int iPeoplenum ,double * dAverin , double * dAverout ,user uScan[]);
//ProgramFunc:主程序函数，传入用户选项iScan与结构体数组uScan[],进行主程序
void ProgramFunc(int iScan,user uScan[]);
//Swap:传入结构体a，b的地址，交换两结构体内容
void Swap(user * a, user * b);
//UserNamesort:传入结构体数组与人数，按姓名排序
void UserNameSort(user uscan[], int iUsernum);
//UserIDsort:传入结构体数组与人数，按ID排序
void UserIDSort(user uscan[], int iUsernum);

int main()
{
    user uScan[MAXNNUM];
    Promptword();
    printf("Please enter your choice:");
    scanf("%d",&iChoiceScan);
    //利用循环限制必须先输入1
    while (iChoiceScan!=1)
    {
        printf("There is no data yet. Please choose 1 to input the data first.\n");
        printf("\nPlease enter your choice:");
        scanf("%d",&iChoiceScan);
    }
    //调用主程序
    while(iChoiceScan)
   {
    ProgramFunc(iChoiceScan,uScan);
    if(iChoiceScan>=1&&iChoiceScan<=6)
    {
        Promptword();
    }
    printf("Please enter your choice:");
    scanf("%d",&iChoiceScan);
   }
    system("pause");
    return 0;
}

void Promptword()
{
    printf("1.Input record\n");
    printf("2.Sort and list records in reverse order by user name\n");
    printf("3.Search records by user name\n");
    printf("4.Calculate and list per capita income and expenses\n");
    printf("5.List records which have more expenses than per capita expenses\n");
    printf("6.List all records\n");
    printf("0．Exit\n");
    return ;
}

void Average(int iPeoplenum ,double * dAverin , double * dAverout,user uScan[] )
{
    int sumin =0;int sumout = 0;
    for(int i=1;i<=iPeoplenum;i++)
    {
        sumin += uScan[i].iIncome;
        sumout += uScan[i].iExpenses;
    }
    * dAverin = (double)sumin /(double) iPeoplenum;
    * dAverout = (double)sumout / (double) iPeoplenum;
}

void Swap(user * a, user * b)
{
    user uTemp;
    uTemp = * a;
    * a = * b;
    * b = uTemp;
}

void UserNameSort(user uscan[], int iUsernum)
{
    //选择排序
    for(int i=1;i<=iUsernum;i++)
    {
        for(int j=i+1;j<=iUsernum;j++)
        {
            if(strcmp(uscan[i].cUserName,uscan[j].cUserName)<0)
            {
                Swap(&uscan[i],&uscan[j]);//按字典序逆序排列
            }
        }
    }
}

void UserIDSort(user uscan[], int iUsernum)
{
    //选择排序  
    for(int i=1;i<=iUsernum;i++)
    {
        for(int j=i+1;j<=iUsernum;j++)
        {
            if(uscan[i].iUserID>uscan[j].iUserID)
            {
                Swap(&uscan[i],&uscan[j]);//按ID降序排列
            }
        }
    }
}

void ProgramFunc(int iScan,user uScan[])
{
    if(iScan==1)
    {
        printf("Input the total of people:");
        scanf("%d",&iPeoplenum);
        while(iPeoplenum>10)
        {
            printf("The system can only store the information of 10 people at most. Please re-enter.\n");
            fflush(stdin);
            printf("\nInput the total of people:");
            scanf("%d",&iPeoplenum);
        }
        printf("Please input user's ID, name, income and expenses: (format as：10001 Cindy 6000 1500)");
        printf("\n");
        int i=1;
        while(i<=iPeoplenum)
        {
            //防止输入多了或少了信息
            if(scanf("%d%s%d%d",&uScan[i].iUserID,uScan[i].cUserName,&uScan[i].iIncome,&uScan[i].iExpenses)!=4)
            {
                printf("Please input again:\n");
                fflush(stdin);
                continue;
            }
            //防止ID错误
            if(uScan[i].iUserID<10000||uScan[i].iUserID>99999)
            {
                printf("Illegal ID.Please input the whole information again:\n");
                continue;
            }
            //防止income数值为负
            if(uScan[i].iIncome<0)
            {
                printf("Illegal income.Please input the whole information again:\n");
                continue;
            }
            i+=1;
        }
        printf("\n");
    }

    else if(iScan==2)
    {
        printf("ID\tUsername\tIncome\tExpenses\n");
        user uTemp[MAXNNUM];
        for(int i=1;i<=iPeoplenum;i++)
        {
            uTemp[i]=uScan[i];
        }
        UserNameSort(uTemp,iPeoplenum);
        for(int i=1;i<=iPeoplenum;i++)
        {
            printf("%d\t%s\t\t%d\t%d\n",uTemp[i].iUserID,uTemp[i].cUserName,uTemp[i].iIncome,uTemp[i].iExpenses);
        }
        printf("\n");
    }

    else if(iScan==3)
    {
        printf("Please input the user name:");
        char Tempname[MAXNNUM];
        scanf("%s",Tempname);
        int icheck=0;
        int i;
        for(i=1;i<=iPeoplenum;i++)
        {
            if(strcmp(Tempname,uScan[i].cUserName)==0)
            {
                printf("ID\tUsername\tIncome\tExpenses\n");
                printf("%d\t%s\t\t%d\t%d\n",uScan[i].iUserID,uScan[i].cUserName,uScan[i].iIncome,uScan[i].iExpenses);
                printf("\n");
                icheck=1;
                break;
            }
        }
        if(!icheck)
        {
             printf("Not Found!\n");
            printf("\n");
        }
    }

    else if(iScan==4)
    {
        Average(iPeoplenum ,&dAverin ,&dAverout,uScan);
        printf("Per capita income:%.2lf\n",dAverin);
        printf("Per capita expenses:%.2lf\n",dAverout);
        printf("\n");
    }

    else if(iScan==5)
    {
        printf("ID\tUsername\tIncome\tExpenses\n");
        Average(iPeoplenum ,&dAverin ,&dAverout,uScan);
        for(int i=1;i<=iPeoplenum;i++)
        {
            if(uScan[i].iExpenses>dAverout)
            {
                printf("%d\t%s\t\t%d\t%d\n",uScan[i].iUserID,uScan[i].cUserName,uScan[i].iIncome,uScan[i].iExpenses);
            }
        }
        printf("\n");
    }
  
    else if(iScan==6)
    {
        user uTemp[MAXNNUM];
        for(int i=1;i<=iPeoplenum;i++)
        {
            uTemp[i]=uScan[i];
        }
        printf("ID\tUsername\tIncome\tExpenses\n");
        UserIDSort(uTemp,iPeoplenum);
        for(int i=1;i<=iPeoplenum;i++)
        {
            printf("%d\t%s\t\t%d\t%d\n",uTemp[i].iUserID,uTemp[i].cUserName,uTemp[i].iIncome,uTemp[i].iExpenses);
        }
        printf("\n");
    }
   
    else if(iScan==0)
    {
        return ;
    }
    else
    {
        printf("Input Error!\n");
        fflush(stdin);//清空缓冲区以便重新输入
    }
   
}