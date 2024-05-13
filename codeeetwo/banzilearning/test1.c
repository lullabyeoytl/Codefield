#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 85
char Stra[maxn],Strb[maxn];
int icheck=0;
//cStrCheck:输入母字符串str1[],子字符串str2[],str1长度iLen1,str2长度iLen2,即将要判断是否对应的位数iDigit,上一个比对的位数iLast)
//void cStrCheck(char str1[], char str2[],int iLen1,int iLen2,int iDigit,int iLast)
void cStrCheck(char str1[], char str2[],int iLen1,int iLen2,int iDigit,int * iLast)
{
    //iDigit==iLen2表明已经判断完符合题意
    if(iDigit==iLen2)
    {
        printf("Yes");
        icheck=1;
        return;
    }
    //初始开始状态
    else if(iDigit==0)
    {
        char * pi = &str1[0];
        for( ;  * pi != '\0'; pi++ )
        {
            if( * pi ==str2[iDigit])
            {
                cStrCheck(str1,str2,iLen1,iLen2,iDigit+1, pi );
                if(icheck)
                {
                    break;//找到一个符合题意就直接结束
                }
            }
        }
    }
    else
    {
        if( *(iLast+1)==str2[iDigit])
        {
            cStrCheck(str1,str2,iLen1,iLen2,iDigit+1,iLast+1);
        }
    }
}

int main()
{
    gets(Stra);
    gets(Strb);
    icheck=0;
    cStrCheck(Stra,Strb,strlen(Stra),strlen(Strb),0,&Stra[0]);
    if(!icheck)
    {
        printf("No");
    }
    system("pause");
    return 0;
}