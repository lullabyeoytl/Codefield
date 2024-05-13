#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define num_elect 10
#define num_canditate 3
struct canditate
{
    char name[20];
    int count;
};
struct canditate a[3] = {"li",0,"zhang",0,"wang",0};
int main()
{
    int i,j,check=1,wrong =0;
    char name[20];
    for(i=1;i<=num_elect;i++)
    {
        printf("input vote %d: ",i);
        gets(name);
        check =1;
        for(j=0;j<num_canditate;j++)
        {
            if(strcmp(name,a[j].name)==0)
            {
                a[j].count += 1;
                check=0;
            }
        }
        if(check)
        {
            wrong+=1;
        }
    }
    for(i=0;i<num_canditate;i++)
    {
        printf("%8s:%d\n",a[i].name,a[i].count);
    }
    printf("Wrong election:%d\n",wrong);
    system("pause");
    return 0;
}
