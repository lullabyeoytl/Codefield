#include <stdio.h>
void one_three(void);
void two(void);//函数声明
int main(void)
{
    printf("starting now: \n");//第一步
    one_three();//调用函数，函数内容在main函数外补充，有提要求two函数应在onethree里方可满足要求
    printf("well done \n");
    getchar();//防止闪退的一个函数
    return 0 ;
}
void one_three(void)
{
    printf("one \n");
   two();//同理，这里要写的不是void two(void)然后写two,你定义的函数里只能调用函数不能在其中执行two&定义two
    printf("three \n");
}
void two(void)//这里再定义two
{
    printf("two \n");
}
//过程中反复的错误是函数里不用来定义函数，只用来调用函数，具体函数定义列在外。



    