/*
题目，编写程序提示用户输入大写字母，使用用户输入大写字母，使用嵌套循环以金字塔的格式打印如下形式的
 A
 ABA
 ABCBA
 ABCDCBA
 ABCDEDCBA的字母金字塔，以上为输入E的结果
#include <stdio.h>
int main(void)
{
     for(int i = 1;i <6;i++)
    {
           char c = 'A';
           int j=1;
           for(;j<=i;j++)
           {
            printf("%c",c);
            c += 1;
           }
           do
           {
            j-=1
           } while ({/* condition });
           

    }
    getchar();
return 0;

}*/  //以上错误的想法
//订正
#include <stdio.h>
int main (void)
{
    int i,j,num;
    char c;
    printf("Enter the core char you want to print");
    scanf("%c",&c);
    char ch = 'A';
    num = c-'A'+1;//这个就是总行数
    for(i = 1; i <=num;i++)//标准的外层循环控制打印行数
    {
       for(j=0;j < num - i ;j++)
       printf("");//先打空格
       for(ch = 'A'; j < num ; j++)//注意这里利用了j已经通过了一次循环有赋值了，实在不行再定义一个变量来操作就好
       printf("%c", ch++);
       for(j = 1, ch-=2/*这里要注意char在上面的print中print完后多加了一个，所以是减2*/;j < i ; j++,ch--)
       printf("%c",ch);
       printf("\n");//笑死，完全可以在末尾补一个换行啊啊啊

    }
    getchar();
    getchar();
    return 0;

}
//总结起来大框架就是如果每行要进行的操作实际类似，那么先用个for构成大框架做行的循环，然后每列再来加，注意变量变成了什么值。
//分析时不构成大框架的小细节可以先不严谨中文代替，再来补
